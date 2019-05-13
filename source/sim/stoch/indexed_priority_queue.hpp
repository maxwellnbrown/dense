#include <utility>
#include <functional>
#include <type_traits>

namespace dense {
namespace stochastic {

  template <
    typename I,
    I Capacity,
    typename T,
    typename Compare = std::less<T>
  >
  class indexed_priority_queue {

    private:

      enum class ignore {};

      template <typename E>
      using underlying_if_enum = std::conditional_t<
        std::is_enum<E>::value,
        std::underlying_type_t<std::conditional_t<std::is_enum<E>::value, E, ignore>>, E>;

    public:

      using size_type = std::ptrdiff_t;
      using index_type = I;
      using node_type = underlying_if_enum<index_type>;
      using mapped_type = T;
      using value_type = std::pair<index_type, mapped_type>;
      using mapped_compare = Compare;
      using iterator = value_type*;
      using const_iterator = value_type const*;
      using reference = value_type&;
      using const_reference = value_type const&;
   
      indexed_priority_queue() {
        _map.fill(_capacity);
      };
      indexed_priority_queue(Compare compare) : _compare{compare} {
        _map.fill(_capacity);
      };

      constexpr size_type capacity() const { return _capacity; }
      size_type size() const { return _size; };
      bool empty() const { return _size == 0; };

      // pre: value does not have an index that is already in pq
      void push(value_type value) {
        // if the index is already present, updates the time
        auto i = static_cast<node_type>(value.first);
        if (_map[i] == _capacity) {
          _heap[_size] = value;
          _map[i] = _size;
          ++_size;
          sift_up();
        } else {
          _heap[_map[i]] = value;
          sift_from(_map[i]);
        }
      };

      // pre: pq is not empty
      void pop() {
        if (empty()) return;
        auto i = static_cast<node_type>(top().first);
        auto top = root();
        auto bottom = last();
        if (bottom != top) {
          swap(top, bottom);
        }
        --_size;
        sift_down();
        _map[i] = _capacity;
      };

      const_iterator begin() const {
        return &top();
      };

      const_iterator end() const {
        return &_heap[last() + 1];
      };

      const_reference top() const { return _heap[root()]; };

      mapped_type const& operator[](index_type i) const {
        return _heap[_map[i]].second;
      };

      const_iterator find(index_type i) const {
        return _map[i] == _capacity ? end() : &operator[](i);
      };

      mapped_type const& at(index_type i) const {
        auto x = find(i);
        if (x == end()) {
          throw std::out_of_range("AIOOBE");
        }
        return *x;
      };


      template <typename... Args>
      void emplace(Args&&... args) {
        push(value_type(std::forward<Args>(args)...));
      };

      indexed_priority_queue (indexed_priority_queue const&) = default;
      indexed_priority_queue (indexed_priority_queue &&) = default;
      indexed_priority_queue& operator=(indexed_priority_queue const&) = default;
      indexed_priority_queue& operator=(indexed_priority_queue &&) = default;
      ~indexed_priority_queue() = default;

    private:

      bool less(node_type a, node_type b) const {
        return _compare(_heap[a].second, _heap[b].second);
      };

      constexpr node_type root() const { return 0; };
      node_type last() const { return _size - 1; };

      node_type parent_of(node_type node) const {
        return ((node + 1) >> 1) - 1;
      };

      node_type left_of(node_type node) const {
        return (node << 1) + 1;
      };

      node_type right_of(node_type node) const {
        return (node + 1) << 1;
      };

      node_type min_child_of(node_type node) const {
        auto left = left_of(node);
        auto right = right_of(node);
        return (right < _size && less(right, left)) ? right : left;
      };

      void swap(node_type a, node_type b) {
        using std::swap;
        swap(_heap[a], _heap[b]);
        _map[static_cast<node_type>(_heap[a].first)] = a;
        _map[static_cast<node_type>(_heap[b].first)] = b;
      };

      bool sift_up(node_type node) {
        node_type start = node, parent;
        while (node != root() && less(node, parent = parent_of(node))) {
          swap(node, parent);
          node = parent;
        }
        return node != start;
      };

      bool sift_up() { return sift_up(last()); }

      bool sift_down(node_type node) {
        node_type start = node, min_child;
        while (left_of(node) < _size && less(min_child = min_child_of(node), node)) {
          swap(node, min_child);
          node = min_child;
        }
        return node != start;
      };

      bool sift_down() { return sift_down(root()); }

      void sift_from(node_type node) {
        sift_up(node) || sift_down(node);
      }

      static constexpr node_type _capacity = static_cast<node_type>(Capacity);
      std::array<value_type, _capacity> _heap;
      std::array<node_type, _capacity> _map;
      node_type _size = static_cast<node_type>(0);
      mapped_compare _compare;
  };

}
}
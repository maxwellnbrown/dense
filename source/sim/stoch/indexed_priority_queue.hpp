#include <utility>
#include <functional>

namespace dense {
namespace stochastic {

  template <
    typename I,
    I _capacity,
    typename T,
    typename Compare = std::less<T>
  >
  class indexed_priority_queue {

    public:

      using size_type = std::ptrdiff_t;
      using index_type = I;
      using mapped_type = T;
      using value_type = std::pair<index_type, mapped_type>;
      using mapped_compare = Compare;
      using iterator = value_type*;
      using const_iterator = value_type const*;
      using reference = value_type&;
      using const_reference = value_type const&;
   
      indexed_priority_queue() : _size{0}, _heap{}, _map{} {
        _map.fill(_capacity);
      };
      indexed_priority_queue(Compare compare) : _compare{compare} {};

      constexpr size_type capacity() const { return _capacity; }
      size_type size() const { return _size; };
      bool empty() const { return _size == 0; };

      // broken
      void push(value_type value) {
        index_type node = last(), parent;
        while (node != root() && less(node, parent = parent_of(node))) {
          swap(node, parent);
          node = parent;
        }
      };

      // UB if called on empty pq
      void pop() {
        auto top = root();
        auto bottom = last();
        if (bottom != top) {
          swap(top, bottom);
        }
        --_size;
        sift_down();
      };

      // also broken
      void replace(value_type value) {
        auto top = root();
        _heap[top] = value;
        _map[_heap[top].first] = top;
        sift_down();
      };

      const_iterator begin() const {
        return &top();
      };

      const_iterator end() const {
        return &_heap[last()];
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
        auto value = value_type(std::forward<Args>(args)...);
        auto i = value.first;
        if (_map[i] == _capacity) {
          push(value);
        } else {
          _heap[_map[i]] = value;
          sift_from(_map[i]);
        }
      };

      indexed_priority_queue (indexed_priority_queue const&) = default;
      indexed_priority_queue (indexed_priority_queue &&) = default;
      indexed_priority_queue& operator=(indexed_priority_queue const&) = default;
      indexed_priority_queue& operator=(indexed_priority_queue &&) = default;
      ~indexed_priority_queue() = default;

    private:

      void less(index_type a, index_type b) const {
        return _compare(_heap[a].second, _heap[b].second);
      };

      constexpr index_type root() const { return 0; };
      index_type last() const { return _size - 1; };

      index_type parent_of(index_type n) const {
        auto x = static_cast<std::underlying_type<index_type>>(n);
        auto y = ((x + 1) >> 1) - 1;
        return static_cast<index_type>(y);
      };

      index_type left_of(index_type n) const {
        auto x = static_cast<std::underlying_type<index_type>>(n);
        auto y = (x << 1) + 1;
        return static_cast<index_type>(y);
      };

      index_type right_of(index_type n) const {
        auto x = static_cast<std::underlying_type<index_type>>(n);
        auto y = (x + 1) << 1;
        return static_cast<index_type>(y);
      };

      index_type min_child_of(index_type node) const {
        auto x = static_cast<std::underlying_type<index_type>>(node);
        auto left = left_of(node);
        auto right = right_of(node);
        auto y = (right < _size && less(right, left)) ? right : left;
        return static_cast<index_type>(y);
      }

      void swap(index_type a, index_type b) {
        using std::swap;
        swap(_heap[a], _heap[b]);
        _map[_heap[a].first] = a;
        _map[_heap[b].first] = b;
      };

      void sift_up() {
        index_type node = last(), parent;
        while (node != root() && less(node, parent = parent_of(node))) {
          swap(node, parent);
          node = parent;
        }
      };

      void sift_down() {
        index_type node = root(), left, right;
        while (
          left = left_of(node), right = right_of(node),
          (left < _size && less(left, node)) ||
          (right < _size && less(right, node))
        ) {
          auto min_child = min_child_of(node);
          swap(node, min_child);
          node = min_child;
        }
      };

      void sift_from(index_type node) {
        index_type min_child, parent;
        for (;;) {
          if (node != root() && less(node, parent = parent_of(node))) {
            swap(node, parent);
            node = parent;
          } else if (left_of(node) < _size && less(min_child = min_child_of(node), node)) {
            swap(node, min_child);
            node = min_child;
          } else {
            break;
          }
        }
      }

      std::array<value_type, _capacity> _heap;
      std::array<index_type, _capacity> _map;
      index_type _size;
      mapped_compare _compare;
  };

}
}
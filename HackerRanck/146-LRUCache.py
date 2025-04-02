class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.order = []
        self.values = {}

    def get(self, key):
        if self.values.__contains__(key):
            pos = self.values[key][1]
            self.order
            return self.values[key]
        return -1

    def put(self, key: int, value: int):
        if self.values.__contains__(key):
            self.values[key] = value
        else:
            if len(self.order) == self.capacity:
                self.values.pop(self.order[0])
                self.order = self.order[1:]
            self.values[key] = [value, len(self.order)]
            self.order.append(key)

    def get_order(self):
        return self.order


order = [1, 2, 3, 4, 5]
lru = LRUCache(3)

for o in order:
    lru.put(o, o)
    lru.get(2)
    print(lru.get_order())

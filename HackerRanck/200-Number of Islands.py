def set_matrix_position(matrix, pos, value):
    matrix[pos[0]][pos[1]] = value


def get_matrix_position(matrix, pos):
    return matrix[pos[0]][pos[1]]


def create_position(col, row):
    print([row, col])
    return [row, col]


def get_surrounding_positions(pos, max_col, max_row):
    surrounding_positions = []
    if pos[0] - 1 > 0:
        surrounding_positions.append([pos[0] - 1, pos[1]])
    if pos[0] + 1 < max_row:
        surrounding_positions.append([pos[0] + 1, pos[1]])
    if pos[1] + 1 < max_col:
        surrounding_positions.append([pos[0], pos[1] + 1])
    if pos[1] - 1 > 0:
        surrounding_positions.append([pos[0], pos[1] - 1])
    return surrounding_positions


class NumberOfIslands:
    def __init__(self, island_map):
        self.visit = []
        self.island_map = island_map
        self.num_of_island = 0
        self.map_cols = 0
        self.map_rows = len(island_map)
        self.__initialize_visit()
        self.__count_islands()

    def __initialize_visit(self):
        if self.map_rows > 0:
            self.map_cols = len(self.island_map[0])
            self.visit = [[False] * self.map_cols for _ in range(self.map_rows)]

    def __count_islands(self):
        for r in range(self.map_rows):
            for c in range(self.map_cols):
                pos = create_position(c, r)
                if not get_matrix_position(self.visit, pos) and get_matrix_position(self.island_map, pos) == "1":
                    self.num_of_island += 1
                    self.__bfs(pos)

    def __bfs(self, init):
        queue = [init]
        set_matrix_position(self.visit, init, True)
        while len(queue) != 0:
            pos = queue.pop()
            surrounding_positions = get_surrounding_positions(pos, self.map_cols, self.map_rows)
            for spos in surrounding_positions:
                if not get_matrix_position(self.visit, spos) and get_matrix_position(self.island_map, spos) == "1":
                    set_matrix_position(self.visit, spos, True)
                    queue.append(spos)


grid = [
    ["1", "1", "1", "1", "0"],
    ["1", "1", "0", "1", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "0", "0", "1"],
]
nm = NumberOfIslands(grid)
print(nm.visit, " ", nm.map_rows, " ", nm.map_cols, " ----- > ", nm.num_of_island)

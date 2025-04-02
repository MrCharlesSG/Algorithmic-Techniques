from typing import List


def create_graph(n: int, headID: int, manager: List[int]):
    graph = [[] for _ in range(n)]

    for i, m in enumerate(manager):
        if m != -1:
            graph[m].append(i)
    return graph


def get_max_time(n: int, graph: List[list], headID: int, inform_time: List[int]):
    queue = [headID]
    dist = [0 for _ in range(n)]
    max_dist = 0
    dist[headID] = inform_time[headID]
    while len(queue) != 0:
        v = queue.pop()
        queue += graph[v]
        for w in graph[v]:
            dist[w] = dist[v] + inform_time[w]
            if max_dist < dist[w]:
                max_dist = dist[w]
    return max_dist


number = 6
headID_data = 2
manager_data = [2, 2, -1, 1, 2, 3]
inform_type_data = [0, 0, 1, 3, 8, 4]

graph = create_graph(number, headID_data, manager_data)
print(get_max_time(number, graph, headID_data, inform_type_data))

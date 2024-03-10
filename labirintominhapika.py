def is_solvable(maze):
    n = len(maze)
    m = len(maze[0])

    # Criando uma matriz para registrar as células visitadas
    visited = [[False for j in range(m)] for i in range(n)]

    # Definindo a posição inicial e adicionando à fila de busca
    start = (0, 0)
    queue = [start]
    visited[start[0]][start[1]] = True

    # Executando a busca em largura
    while queue:
        x, y = queue.pop(0)
        if x == n-1 and y == m-1:
            return True
        for dx, dy in [(0,1), (1,0), (0,-1), (-1,0)]:
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and maze[nx][ny] == 0:
                visited[nx][ny] = True
                queue.append((nx, ny))
    
    # Não foi possível encontrar um caminho válido
    return False


def parse_input(input_string):
    input_list = input_string.strip().split('\n')
    n, m = map(int, input_list[0].split())
    maze = []
    for i in range(1, n+1):
        maze.append([1 if c == '#' else 0 for c in input_list[i]])
    return maze


    
    
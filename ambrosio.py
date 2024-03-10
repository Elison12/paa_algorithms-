def maior_numero_itens(dinheiro_disponivel, lista_materiais):
    # Inicializa a matriz com zeros
    matriz = [[0 for j in range(int(dinheiro_disponivel))] for i in range(len(int(lista_materiais)))]
    
    # Preenche a matriz
    for i in range(1, len(lista_materiais) + 1):
        c, v = lista_materiais[i-1]
        for j in range(1, dinheiro_disponivel + 1):
            if c <= j:
                matriz[i][j] = max(matriz[i-1][j], matriz[i-1][j-c] + v)
            else:
                matriz[i][j] = matriz[i-1][j]
    
    # Reconstrói a solução
    solucao = []
    i = len(lista_materiais)
    j = dinheiro_disponivel
    while i > 0 and j > 0:
        if matriz[i][j] != matriz[i-1][j]:
            solucao.append(lista_materiais[i-1])
            j -= lista_materiais[i-1][0]
        i -= 1
    
    # Retorna a solução e o dinheiro sobrando
    dinheiro_sobrando = dinheiro_disponivel - sum(c for c, v in solucao)
    return solucao, dinheiro_sobrando


dinheiro_disponivel = float(input())
n = int(input())
lista_materiais = []
for i in range(n):
    nome, preco = input().split()
    lista_materiais.append((float(preco), nome))

solucao, dinheiro_sobrando = maior_numero_itens(dinheiro_disponivel, [(c, v) for v, c in lista_materiais])
for v, c in solucao:
    print(c)
print('%.2f' % dinheiro_sobrando)


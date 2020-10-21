#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

typedef struct GraphNode
{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;// 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화
void graph_init(GraphType* g)

{

    int v;

    g->n = 0;

    for (v = 0; v < MAX_VERTICES; v++)

        g->adj_list[v] = NULL;

}

// 정점 삽입 연산

void insert_vertex(GraphType* g, int v)

{

    if (((g->n) + 1) > MAX_VERTICES) {

        fprintf(stderr, "그래프: 정점의 개수 초과");

        return;

    }

    g->n++;

}

// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.

void insert_edge(GraphType* g, int u, int v)

{

    GraphNode* node;

    if (u >= g->n || v >= g->n) {

        fprintf(stderr, "그래프: 정점 번호 오류");

        return;

    }

    node = (GraphNode*)malloc(sizeof(GraphNode));

    node->vertex = v;

    node->link = g->adj_list[u];

    g->adj_list[u] = node;

}



GraphType g;



void generate(int arr[], int s, int size, int* in) {

    int i, tmp;

    int in_degree[MAX_VERTICES];

    for (i = 0; i < g.n; i++)// copy

        in_degree[i] = in[i];



    //각 정점의 진입 차수 변경을 완성하시오.







    s++;

    if (s == g.n) {

        for (i = 0; i < g.n; i++)

            printf("정점%d->", arr[i]);

        printf("\n");

    }

    else {

        for (i = s; i < size; i++) {

            SWAP(arr[s], arr[i], tmp);

            generate(arr, s, size, in_degree);

            SWAP(arr[s], arr[i], tmp);

        }

    }

}

// 위상정렬을 수행한다.

void topo_sort()

{

    int i, j, tmp;

    int arr[MAX_VERTICES], size;

    int in_degree[MAX_VERTICES];



    // 모든 정점의 진입 차수를 계산

    for (i = 0; i < g.n; i++)// 초기화

        in_degree[i] = 0;

    for (i = 0; i < g.n; i++) {

        GraphNode* node = g.adj_list[i];//정점 i에서 나오는 간선들

        while (node != NULL) {

            in_degree[node->vertex]++;

            node = node->link;

        }

    }

    // 진입 차수가 0인 정점을 배열에 삽입

    size = 0;

    for (i = 0; i < g.n; i++) {

        if (in_degree[i] == 0)

            arr[size++] = i;

    }

    // 모든 위상 순서를 생성

    for (i = 0; i < size; i++) {

        SWAP(arr[0], arr[i], tmp);

        generate(arr, 0, size, in_degree);

        SWAP(arr[0], arr[i], tmp);

    }

}

//

int main(void)

{

    graph_init(&g);

    insert_vertex(&g, 0);

    insert_vertex(&g, 1);

    insert_vertex(&g, 2);

    insert_vertex(&g, 3);

    insert_vertex(&g, 4);

    insert_vertex(&g, 5);



    //정점 0의 인접 리스트 생성

    insert_edge(&g, 0, 2);

    insert_edge(&g, 0, 3);

    //정점 1의 인접 리스트 생성

    insert_edge(&g, 1, 3);

    insert_edge(&g, 1, 4);

    //정점 2의 인접 리스트 생성

    insert_edge(&g, 2, 3);

    insert_edge(&g, 2, 5);

    //정점 3의 인접 리스트 생성

    insert_edge(&g, 3, 5);

    //정점 4의 인접 리스트 생성

    insert_edge(&g, 4, 5);



    //다른 그래프, 3판 p437

    //insert_edge(&g, 0, 1);

    //insert_edge(&g, 0, 2);

    //insert_edge(&g, 0, 3);



    //insert_edge(&g, 1, 4);



    //insert_edge(&g, 2, 4);

    //insert_edge(&g, 2, 5);



    //insert_edge(&g, 3, 5);

    //위상 정렬

    topo_sort();

    // 동적 메모리 반환 코드 생략

    return 0;

}
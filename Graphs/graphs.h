#define MAXV 1000

typedef struct {
    int y;                      // vertex id
    int weight;                 // may be zero
    struct edgenode *next;      // next vertex in adjacency list
} edgenode;

typedef struct {
    // Note, we add one to MAXV so that MAXV will be a valid index
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;

} graph;


void initialize_graph(graph *g, bool directed) {
    int i;
    g -> nvertices = 0;
    g -> nedges = 0;
    g -> directed = directed;

    // Note, we don't use the 0 index
    for (i=1; i<=MAXV; i++) g->degree[i] = 0;
    for (i=1; i<=MAXV; i++) g->edges[i] = NULL;

}

void insert_edge(graph *g, int x, int y, bool directed) {
    edgenode *p;                                // temp pointer
    p = malloc(sizeof(edgenode));

    p->weight = 0;
    p->y = y;

    p->next = g->edges[x];                      // insert at head of list
    g->edges[x] = p;

    g->degree[x] ++;

    if(directed == false) 
        insert_edge(g, y, x, true);
    else
        g->nedges ++;

}

void read_graph(graph *g, bool directed) {
    int i;                                      // counter
    int m;                                      // number of edges
    int x, y;                                   // vertices in edge (x, y) 

    initialize_graph(g, directed);

    scanf("%d, %d", &(g->nvertices), &m);
    
    for (i=1; i<=m; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}


void print_graph(graph *g) {
    int i;
    edgenode *p;

    for (i=1; i<=g->nvertices; i++) {
        printf("%d: ",i);
        p = g->edges[i];
        while (p != NULL) {
            printf("%d: ", i);
            p = g->edges[i];
            while (p != NULL) {
                printf(" %d", p->y);
                p = p->next;
            }
            printf("\n");
        }
    }
}


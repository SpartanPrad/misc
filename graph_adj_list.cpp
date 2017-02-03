    #include <iostream>
    using namespace std;
     
    struct listNode {
    	int dest;
    	struct listNode *next;
    };
     
    struct adjList {
    	struct listNode *head;
    };
     
    struct graph {
    	int v;
    	struct adjList *arr;
    };
     
    struct graph *createGraph(int v) {
    	struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
    	newGraph->v = v;
     
    	newGraph->arr = (struct adjList *)malloc(v * sizeof(struct adjList));
    	for(int i=0;i<v;i++)
    		newGraph->arr[i].head = NULL;
     
    	return newGraph;
     
    }
    
    void addEdge(struct graph *Graph, int src, int dest) {
    	struct listNode *newNode = (struct listNode*)malloc(sizeof(struct listNode));
    	newNode->dest = dest;
    	newNode->next = NULL;
    	
    	newNode->next = Graph->arr[src].head;
    	Graph->arr[src].head = newNode;
    	
    	struct listNode *node = (struct listNode*)malloc(sizeof(struct listNode));
    	node->dest = src;
    	node->next = NULL;
    	
    	node->next = Graph->arr[dest].head;
    	Graph->arr[dest].head = node;
    }
    
    void printGraph(struct graph *Graph) {
    	int v = Graph->v;
    	
    	for(int i=0;i<v;i++) {
    		struct listNode *h = Graph->arr[i].head;
    		while(h){
    			cout<<h->dest;
    			h = h->next;
    		}
    		cout<<endl;
    	}
    }
    
    int main() {
    	// your code goes here
    	int v=5;
    	graph *newGraph = createGraph(v);
     
    	addEdge(newGraph, 0, 1);
        addEdge(newGraph, 0, 4);
        addEdge(newGraph, 1, 2);
        addEdge(newGraph, 1, 3);
        addEdge(newGraph, 1, 4);
        addEdge(newGraph, 2, 3);
        addEdge(newGraph, 3, 4);
     	
     	printGraph(newGraph);
    	return 0;
    }

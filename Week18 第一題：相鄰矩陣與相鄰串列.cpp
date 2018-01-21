#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>    
#include <stdlib.h>  

typedef struct node *link_pointer;

struct node{
	int date;
	link_pointer next;
};

int time[100] = { 0 };

void Adjacency(link_pointer link[], int n[100][100], int *arraymax){
	int a, b;
	while (scanf("%d    %d", &a, &b) == 2){
		n[a][b] = 1; n[b][a] = 1;
		if (a > *arraymax){
			*arraymax = a;
		}
		if (b > *arraymax){
			*arraymax = b;
		}
		link[b]->date = a;
		link[b]->next = (link_pointer)malloc(sizeof(node));
		link[b]->next->date = -1;
		link[b] = link[b]->next;
		link[a]->date = b;
		link[a]->next = (link_pointer)malloc(sizeof(node));
		link[a]->next->date = -1;
		link[a] = link[a]->next;
	}
}

int main(){
	link_pointer *link = (link_pointer*)malloc(100 * sizeof(node)), *graph = (link_pointer*)malloc(100 * sizeof(node));
	for (int i = 0; i < 100; i++){
		link[i] = (link_pointer)malloc(sizeof(node));
		link[i]->date = -1;
		graph[i] = link[i];
	}
	int n[100][100] = { 0 }, arraymax = 0;
	Adjacency(link, n, &arraymax);
	printf("Adjacency matrix:\n");
	for (int x = 0; x <= arraymax; x++){
		for (int y = 0; y <= arraymax; y++){
			printf("%d ", n[x][y]);
		}
		printf("\n");
	}
	printf("\nAdjacency list:\n");
	for (int i = 0; i < 100; i++){
		while (graph[i]->date != -1){
			printf("%d: %d ", i, graph[i]->date);
			time[i]++;
			while (true){
				graph[i] = graph[i]->next;
				if (graph[i]->date == -1){
					printf("-> end\n");
					break;
				}
				else{
					printf("-> %d ", graph[i]->date);
					time[i]++;
				}
			}
		}
	}
	printf("\ndegree:\n");
	int i = 0;
	while (time[i] > 0){
		printf("%d: %d\n", i, time[i]);
		i++;
	}
	return 0;
}

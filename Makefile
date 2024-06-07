dijkstra: comp run

bct: comp_bct
	./bct

comp_bct:

	gcc bct.c -o bct
comp :

	gcc dijkstra.c -o dijkstra
run :
 
	./dijkstra
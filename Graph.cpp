#include "Graph.h"

using namespace std;

Graph::Graph() {

}

bool Graph::edgeExists(Edge* anEdge) {
	for (int i = 0; i < edges.size(); i++) {
		Edge* edge = edges.at(i);
		if (edge->getName == anEdge->getName) {
			return true;
		}
		return false;
	}
}
bool Graph::componentExists(Component* aComponent) {
	for (int i = 0; i < components.size(); i++) {
		Component* component = components.at(i);
		if (component->getName == aComponent->getName) {
			return true;
		}
		return false;
	}
}
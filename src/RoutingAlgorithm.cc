#include "../include/RoutingAlgorithm.h"
#include "../include/DirectedThetaFourGraph.h"

string RoutingAlgorithm::greedyRoutingOnly(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph){
    if(graph.getVertex(xu,yu) == NULL || graph.getVertex(xt,yt) == NULL ) return "Invalid input!";
    
    string path = "";
    ThetaFourVertex *currentVertex = graph.getVertex(xu, yu);
    ThetaFourVertex *targetVertex = graph.getVertex(xt, yt);
    
    while (true){
        path += currentVertex->print(); 
        
        if(currentVertex->equals(xt,yt)) break;

        currentVertex = greedy(currentVertex, targetVertex, graph, 1); //diagonal does not matter here
    }

    return path;
}

 vector<ThetaFourVertex> RoutingAlgorithm::greedyRoutingOnlyReturnPath(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph){
    vector<ThetaFourVertex> path;

    if(graph.getVertex(xu,yu) == NULL || graph.getVertex(xt,yt) == NULL ) throw std::logic_error("vertex does not exists");
    
    ThetaFourVertex *currentVertex = graph.getVertex(xu, yu);
    ThetaFourVertex *targetVertex = graph.getVertex(xt, yt);
    
    while (true){
        path.push_back(*currentVertex); 
        
        if(currentVertex->equals(xt,yt)) break;

        currentVertex = greedy(currentVertex, targetVertex, graph, 1); //diagonal does not matter here
    }

    return path;
 }

string RoutingAlgorithm::GreedySweepRouting(int xu, int yu, int xt, int yt, DirectedThetaFourGraph& graph){
    if(graph.getVertex(xu,yu) == NULL || graph.getVertex(xt,yt) == NULL ) return "Invalid input!";
    
    string path = "";
    ThetaFourVertex *currentVertex = graph.getVertex(xu, yu);
    ThetaFourVertex *targetVertex = graph.getVertex(xt, yt);
    
    int d = getClosestDiagonal(currentVertex, targetVertex, graph);

    while (true){
        path += currentVertex->print(); 
        
        if(currentVertex->equals(xt,yt)) break;

        //greedy/sweep core
        if (isClean(currentVertex, targetVertex, graph, d))
            currentVertex = greedy(currentVertex, targetVertex, graph, d);
        else    
            currentVertex = sweep(currentVertex, targetVertex, graph, d);
     
    }

    return path;
}

int RoutingAlgorithm::getClosestDiagonal(ThetaFourVertex* start, ThetaFourVertex* target, DirectedThetaFourGraph& graph){
    int cone = graph.getCone(*start, *target);
    if(cone == 0 || cone == 2) return -1;
    return 1;
}

ThetaFourVertex* RoutingAlgorithm::greedy(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, int d){
    return u->getNeighbor(graph.getCone(*u, *t));
}

ThetaFourVertex* RoutingAlgorithm::sweep(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, int d){
    int u_X = u->getX().value();
    int u_Y = u->getY().value();

    int t_X = t->getX().value();
    int t_Y = t->getY().value();

    if (d == -1){
        if(u_X + u_Y <= t_X + t_Y) //neighbor is in cone 1
            return u->getNeighbor(1);
        else 
            return u->getNeighbor(3);
    }

    else {//d==1
        if(u_Y - u_X <= t_Y - t_X)
            return u->getNeighbor(2);
        else 
            return u->getNeighbor(0);
    }

}

bool RoutingAlgorithm::isClean(ThetaFourVertex *u, ThetaFourVertex *t, DirectedThetaFourGraph& graph, int d){
    int u_X = u->getX().value();
    int u_Y = u->getY().value();

    int t_X = t->getX().value();
    int t_Y = t->getY().value();

    int n_X;
    int n_Y;

    if(d == -1){
        if(u_X + u_Y <= t_X + t_Y){
            if(u->getNeighbor(1) == NULL){
                return true; 
            } 

            //check neighbor in cone 1
            ThetaFourVertex *neighbor = u->getNeighbor(1);
            n_X = neighbor->getX().value();
            n_Y = neighbor->getY().value();

            if(n_X + n_Y > t_X + t_Y) return true;
            else return false;
        } 
        else{
            if(u->getNeighbor(3) == NULL){
                return true;
            } 
            
            //check neighbor in cone 3
            ThetaFourVertex *neighbor = u->getNeighbor(3);
            n_X = neighbor->getX().value();
            n_Y = neighbor->getY().value();

            if(n_X + n_Y < t_X + t_Y) return true;
            else return false;
        }
    }

    else {
        if(u_Y - u_X <= t_Y - t_X){
            if(u->getNeighbor(2) == NULL){
                return true; // no neighbor in that cone
            } 
            
            ThetaFourVertex *neighbor = u->getNeighbor(2);
            n_X = neighbor->getX().value();
            n_Y = neighbor->getY().value();
            
            if(n_Y - n_X > t_Y - t_X) return true;
            else return false;
        }
        else{
            if(u->getNeighbor(0) == NULL){
                return true; // no neighbor in that cone
            } 

            ThetaFourVertex *neighbor = u->getNeighbor(0);
            n_X = neighbor->getX().value();
            n_Y = neighbor->getY().value();

            if(n_Y - n_X < t_Y - t_X) return true;
            else return false;
            
        }
    }
}


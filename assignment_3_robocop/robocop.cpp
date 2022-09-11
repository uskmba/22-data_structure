#include <iostream>
using namespace std;

class node {
  private:
    int x_coord, y_coord;
    node * next_node =nullptr;
  public:
    int get_x() {
        return x_coord;
    }
    int get_y() {
        return y_coord;
    }
    node * get_next_node() {
        return next_node;
    }
    void set_x(int x) {
        this->x_coord=x;
    }
    void set_y(int y) {
        this->y_coord=y;
    }
    void set_next_node(node * next_point) {
        this->next_node=next_point;
    }
};

void create_node (int n,node* first) {
    int x, y;
    node* previous_node;
    previous_node=first;
    for(int i = 1 ; i < n ; i++) {
        cin>>x>>y;
        node * current_node = new node;
        current_node->set_x(x);
        current_node->set_y(y);
        previous_node->set_next_node(current_node);
        previous_node = current_node;
    }
    previous_node->set_next_node(first);
}

node* create_list () {
    int x,y;
    cin>>x>>y;

    node * first_node;
    first_node = new node;

    first_node->set_x(x);
    first_node->set_y(y);
    return first_node;
}

void link_yaxis(node *current,node *next) {
    int y1 = current->get_y(), y2 = current->get_y(),x = current->get_x();
    node * working_node = current;
    for(int i = y1; i<y2; ++i) {
        node * new_node = new node;
        new_node->set_x(x);
        new_node->set_y(i);
        working_node->set_next_node(new_node);
        working_node = new_node;
    }
    working_node->set_next_node(next);
}

void link_xaxis(node *current,node *next) {
    int x1 = current->get_x(), x2 = current->get_x(),y = current->get_y();
    node * working_node = current;
    for(int i = x1; i<x2; ++i) {
        node * new_node = new node;
        new_node->set_y(y);
        new_node->set_x(i);
        working_node->set_next_node(new_node);
        working_node = new_node;
    }
    working_node->set_next_node(next);
}

void link_path(int n, node * path_list) {
    node * current=path_list, *next;
    next = current->get_next_node();
    for(int i = 0 ; i < n ; i++) {
        if(current->get_x() == next->get_x())
            link_yaxis(current,next);
        else
            link_xaxis(current,next);
        current->set_next_node(next);
        next->set_next_node(next->get_next_node());
    }
}

void print_list(int n, node* first) {
    node* current;
    current=first;
    for(int i = 0; i<n; i++) {
        cout << "xco : "<<current->get_x() << " yco : "<<current->get_y() <<endl;
        current = current->get_next_node();
    }

}

void find_location(int t, node* path_list ) {

    node* loc = path_list;
    for(int cnt= 0 ; cnt < t ; cnt++) {
        loc = loc->get_next_node();
    }
    cout << "xco : " << loc->get_x() << " yco : " << loc->get_y() <<endl;

}
int main () {

    int n,t ;
    cin>>n;
    node* path_list;
    path_list = create_list();
    create_node(n,path_list);
    link_path(n,path_list);
    print_list(18,path_list);

}



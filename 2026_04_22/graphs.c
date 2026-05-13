
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
    char value;
    struct node* next_node;
    struct node* next_set;
} node;

typedef struct s_string_array
{
    int size;
    char** array;
} string_array;

int check_equality(char* str){
    if (str[1] == '=')
        return 1;
    else
        return 0;
    // return str[1] == '=' ? 1 : 0;
}

node* create_set(char value1, char value2){
    node* node1 = malloc(sizeof(node));
    node1->value = value1;
    node1->next_set = NULL;

    // if values are the same, we create only one node to avoid unnecessary duplicates
    if (value1 != value2) {
        node* node2 = malloc(sizeof(node));
        node2->value = value2;
        node1->next_node = node2;
        node2->next_node = NULL;
        node2->next_set = NULL;
    } else {
        node1->next_node = NULL;
    }

    return node1;
}

node* check_if_node_exist(node* head, char value){
    node* set_copy = head;
    while(set_copy != NULL){
        node* node_copy = set_copy;
        while (node_copy != NULL){
            if(node_copy->value == value) {
                printf("node %c exists\n", value);
                return set_copy;
            }
            node_copy = node_copy->next_node;
        }
        set_copy = set_copy->next_set;
    }
    printf("node %c does not exist\n", value);
    return NULL;
}

node* get_tail_set(node* head){
    node* copy = head;
    while(copy->next_set != NULL){
        copy = copy->next_set;
    }
    return copy;
}

node* get_tail_node(node* head){
    node* copy = head;
    while(copy != NULL && copy->next_node != NULL){
        copy = copy->next_node;
    }
    return copy;
}

void merge_sets(node* root1, node* root2, node* head){
    // if root2 is the head, swap root to always merge into head
    if (root2 == head) {
        root2 = root1;
        root1 = head;
    }

    // we make the last node of root1 set to point on root2 node
    node* root1_tail = get_tail_node(root1);
    root1_tail->next_node = root2;

    // we look for a set head that is pointing on root2 as its next set
    node* copy = head;
    while (copy->next_set != root2){
        copy = copy->next_set;
    }

    // and make the found set head pointing to the next set of root2 instead
    copy->next_set = root2->next_set;
    root2->next_set = NULL;
}

void create_node(node* root, char value){
    node* root_tail = get_tail_node(root);
    node* created_node = malloc(sizeof(node));
    created_node->value = value;
    created_node->next_set = NULL;
    created_node->next_node = NULL;
    root_tail->next_node = created_node;
}

void print_all_nodes(node* head){
    node* set_copy = head;
    while (set_copy != NULL){
        node* node_copy = set_copy;
        while (node_copy != NULL){
            printf("%c --- ", node_copy->value);
            node_copy = node_copy->next_node;
        }
        printf("\n");
        set_copy = set_copy->next_set;
    }
}

bool satisfiability_of_equality_equations(string_array* param_1){
    node* head = NULL;
    node* inequalities = NULL;
    for (int i = 0; i < param_1->size; i++){
        char value1 = param_1->array[i][0];
        char value2 = param_1->array[i][3];
        printf("val1: %c val2:%c\n", value1, value2);
        fflush(stdout);
        if (check_equality(param_1->array[i])){
            if (head == NULL) {
                head = create_set(value1, value2);
                printf("initializing equality graph\n");
                continue;
            }
            printf("equality graph already initialized\n");
            node* root1 = check_if_node_exist(head, value1);
            node* root2 = check_if_node_exist(head, value2);
            if (!root1 && !root2){
                printf("creating new set\n");
                node* tail = get_tail_set(head);
                tail->next_set = create_set(value1, value2);
            }
            else if (root1 && !root2){
                printf("adding %c to %c set\n", value2, root1->value);
                create_node(root1, value2);
            }
            else if (root2 && !root1){
                printf("adding %c to %c set\n", value1, root2->value);
                create_node(root2, value1);
            }
            else if (root1 != root2){
                printf("try and merge sets\n");
                merge_sets(root1, root2, head);
            }
            else if (root1 == root2){
                printf("roots are the same, skipping\n");
                continue;
            }
            printf("printing equalities:\n");
            print_all_nodes(head);
        }
        else {
            if (inequalities == NULL){
                inequalities = create_set(value1, value2);
                printf("initializing inequality graph\n");
                continue;
            }
            printf("inequality graph already initialized\n");
            node* root1 = check_if_node_exist(inequalities, value1);
            node* root2 = check_if_node_exist(inequalities, value2);
            if (!root1 && !root2){
                printf("creating new set\n");
                node* tail = get_tail_set(inequalities);
                tail->next_set = create_set(value1, value2);
            }
            printf("printing inequalities:\n");
            print_all_nodes(inequalities);
        }
    }
    return true;
}
/*
Both sets present:
Global/minimal O(): O(n+1)/o(n+1-k)
Check on every equasion:
Global/minimal O(): O(Sum of 1..(n))/o(Sum of 2..(n-k)) -> not true, much bigger estimation
where k is number less than n
*/
int main(){
    char test1[] = "a==a";
    char test2[] = "a==b";
    char test3[] = "a==d";
    char test4[] = "e==f";
    char test5[] = "e==a";
    char** array = malloc(sizeof(char*) * 5);
    array[0] = strdup(test1);
    array[1] = strdup(test2);
    array[2] = strdup(test3);
    array[3] = strdup(test4);
    array[4] = strdup(test5);
    string_array* str_arr = malloc(sizeof(string_array));
    str_arr->size = 5;
    str_arr->array = array;
    satisfiability_of_equality_equations(str_arr);
    return 0;
}
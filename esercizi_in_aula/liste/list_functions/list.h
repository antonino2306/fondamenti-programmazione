struct _node {
    char letter;
    struct _node *next;
};

typedef struct _node Node;

extern Node *init_list(unsigned int list_length);
extern void print_list(Node *head);
extern void free_list(Node *head);
extern Node *insert_head(Node *head, int value);
extern Node *remove_head(Node *head);
extern Node *remove_tail(Node *head);
extern Node *remove_by_value(Node *head, char element);
extern void print_list_ric(Node *head);
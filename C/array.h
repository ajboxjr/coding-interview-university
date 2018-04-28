
struct Vector;

typedef struct Vector {
    long int cap;
    long int size;
    int * items;
} Vector;

void _resize(Vector * arr, double multiplier);
void init(Vector * arr, long int max);
long int at(Vector * arr, long int pos);
bool is_empty(Vector * arr);
long int capacity(Vector * arr);
long int size(Vector * arr);
void push(Vector * arr, long int item);
void handle_resize(Vector * arr, long int adjust);
void printVector(Vector * arr);
void remove(Vector * arr, int item);
int find(Vector * arr, int item);
void prepend(Vector * arr, int item);
void pop(Vector * arr);
void delete(Vector * arr, long int index);
void remove_item(Vector * arr, int item);
int find(Vector * arr, int item);


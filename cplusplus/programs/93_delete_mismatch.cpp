
int main() {
    int* a = new int[3];
    delete a; // WRONG
    //delete[] a; // RIGHT
}
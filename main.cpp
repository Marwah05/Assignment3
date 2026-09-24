#include <iostream>
class Box {
    public:
    Box(int value): data(new int(value)) {}

    ~Box() {
        delete data;
        data = nullptr;
    }
    int value() {
        return *data;
    }
    private:
    int *data;
};
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // int x = 5;
    // int* p = &x; // pointer p- in the stack memory
    // std::cout << x << std::endl;
    // std::cout << *p << std::endl; // dereferencing - prints value inside the address
    // std::cout << p << std::endl; // referencing - prints the address itself
    // *p =10;
    // std::cout << *p << std::endl;
    // std::cout << &x << std::endl;

    // int* p = new int(5);
    // std::cout << *p << std::endl;
    // std::cout << p << std::endl;
    // delete p; // destructor in classes
    // p = nullptr;

    Box *box1 = new Box(6);
    std::cout << box1->value() << std::endl;
    delete box1;

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
#include <iostream>
#include <string>

class OldPrinter {
public:
    void printText(const std::string &text) {
        std::cout << "Old Printer: " << text << std::endl;
    }
};

class ModernPrinter {
public:
    virtual void printDocument(const std::string &document) = 0;
};

class PrinterAdapter : public ModernPrinter {
private:
    OldPrinter &oldPrinter;

public:
    PrinterAdapter(OldPrinter &printer) : oldPrinter(printer) {}

    void printDocument(const std::string &document) override {
        oldPrinter.printText(document);
    }
};

int main(int argc, char* []) {
    OldPrinter oldPrinter;
    PrinterAdapter adapter(oldPrinter);

    adapter.printDocument("Hello, Adapter Pattern!");

    return 0;
}

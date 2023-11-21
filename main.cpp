#include "CompanyManagementProgram.h"

int main() {
    std::vector<Employee*> employees{};
    CompanyManagementProgram program(employees);
    program.run();

    return 0;
}

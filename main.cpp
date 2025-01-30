#include "CompanyManagementProgram.h"
#include <vector>

int main() {
    std::vector<Employee*> employees;
    std::vector<Client*> clients;

    CompanyManagementProgram program(employees, clients);
    program.run();

    return 0;
}

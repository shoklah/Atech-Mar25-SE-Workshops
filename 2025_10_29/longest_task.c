#include <stdio.h>
#include <stdlib.h>

int count_different_employees(int n, int **task_logs, int logs_size) {
    int *employees = malloc(sizeof(int) * n);
    int employee_id = -1;
    int employees_count = 0;

    if (employees == NULL)
        return -1;
    for (int i = 0; i < n; i++) {
        employees[i] = 0;
    }

    for (int i = 0; i < logs_size; i++) {
        employee_id = task_logs[i][0];
        employees[employee_id] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (employees[i] == 1) {
            employees_count++;
        }
    }

    free(employees);
    return employees_count;
}

int get_billable_index(int **employees_billable, int employees_count, int employee_id) {
    int free_index = -1;

    for (int i = 0; i < employees_count; i++) {
        if (employees_billable[i][0] == employee_id)
            return i;
        if (employees_billable[i][0] == -1 && free_index == -1) {
            free_index = i;
        }
    }

    return free_index;
}

int **count_employees_billable(int **employees_billable, int employees_count, int **task_logs, int logs_size) {
    int starting_time = 0;
    int finishing_time = 0;
    int employee_id = -1;
    int time_spent = 0;
    int billable_index = -1;

    for (int i = 0; i < logs_size; i++) {
        finishing_time = task_logs[i][1];
        time_spent = finishing_time - starting_time;
        starting_time = finishing_time;

        employee_id = task_logs[i][0];
        billable_index = get_billable_index(employees_billable, employees_count, employee_id);
        employees_billable[billable_index][1] += time_spent;
    }

    return employees_billable;
}

int get_max_working_employee_id(int **employees_billable, int employees_count) {
    int max_time = -1;
    int max_time_employee_id = -1;
    int employee_id = -1;
    int time_spent = -1;

    for (int i = 0; i < employees_count; i++) {
        employee_id = employees_billable[i][0];
        time_spent = employees_billable[i][1];
        printf("%d %d\n", time_spent, max_time);

        if (time_spent > max_time || 
            (time_spent == max_time && max_time_employee_id > employee_id)
        ) {
            max_time = time_spent;
            max_time_employee_id = employee_id;
        }
    }

    return max_time_employee_id;
}

int free_array(int **array, int size) {
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);

    return 1;
}

int main() {
    int task_logs_to_copy[4][2] = {{0, 3}, {2, 5}, {0, 9}, {1, 15}};
    int n = 10;
    
    int **task_logs = malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; i++) {
        task_logs[i] = malloc(sizeof(int) * 2);
        task_logs[i][0] = task_logs_to_copy[i][0];
        task_logs[i][1] = task_logs_to_copy[i][1];
    }


    int employees_count = count_different_employees(n, (int **)task_logs, 4);
    int **employees_billable = malloc(sizeof(int *) * employees_count);
    
    if (employees_billable == NULL) {
        return -1;
    }
    for (int i = 0; i < employees_count; i++) {
        employees_billable[i] = malloc(sizeof(int) * 2);

        if (employees_billable[i] == NULL)
            return -1;

        employees_billable[i][0] = -1;
        employees_billable[i][1] = 0;
    }

    employees_billable = count_employees_billable(employees_billable, employees_count, (int **)task_logs, 4);
    printf("%d\n", get_max_working_employee_id(employees_billable, employees_count));

    free_array(employees_billable, employees_count);


}




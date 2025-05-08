#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    char name[50];
    char email[20];
    int age;
    int num_users ;
    int emp_id;
    printf("how many number of user data you want :\n");
    scanf("%d",&num_users);

    cJSON *users_array = cJSON_CreateArray();

    for (int i = 0; i < num_users; i++) {
        printf("Enter name of empolyee %d: ", i + 1);
        scanf("%s", name);

        printf("Enter age of empolyee %d: ", i + 1);
        scanf("%d", &age);
        
        printf("Enter empolyee ID %d: ", i + 1);
        scanf("%d", &emp_id);
        
        printf("Enter employee email ID %d: ", i + 1);
        scanf("%s", email);

        cJSON *user = cJSON_CreateObject();
        cJSON_AddStringToObject(user, "name", name);
        cJSON_AddNumberToObject(user, "age", age);
        cJSON_AddNumberToObject(user, "empolyee id", emp_id);
        cJSON_AddStringToObject(user, "email", email);

        cJSON_AddItemToArray(users_array, user);
    }

    char *json_string = cJSON_Print(users_array);
    printf("\nGenerated JSON:\n%s\n", json_string);

    // Write JSON string to file
    FILE *file = fopen("output.json", "w");
    if (file == NULL) {
        perror("Error opening file");
        free(json_string);
        cJSON_Delete(users_array);
        return 1;
    }

    fprintf(file, "%s\n", json_string);
    fclose(file);
    printf("JSON data written to output.json\n");

    // Clean up
    free(json_string);
    cJSON_Delete(users_array);

    return 0;
}


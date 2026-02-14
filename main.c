#include "init.h"
#include <unistd.h>

int main()
{
    system("clear");
    int choice;
    // printf("Lo");
    system("sl");
    printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
    printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" NORMAL);

    do
    {
        printf(BOLD "\n1.Add Vehicle \n2.Show Vehicle/s \n3.Update Vehicle Info \n4.Delete Vehicle");
        printf("\n5.Search Vehicle/s \n6.BulkDelete Vehicle/s Info \n7.Summary");
        printf("\n8.Group Vehicles\n9.Undo Action\n0.Exit\nChoice: " NORMAL);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("clear");
            printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
            printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" NORMAL);
            addVehicle();
            break;
        case 2:
            system("clear");
            printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
            printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" NORMAL);
            showVehicles();
            break;
        case 3:
            system("clear");
            printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
            printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" NORMAL);
            updateVehicle();
            break;
        case 4:
            system("clear");
            printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
            printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" NORMAL);
            deleteVehicle();
            break;
        case 5:
            system("clear");
            printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
            printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" NORMAL);
            searchAny();
            break;
        case 6:
            system("clear");
            printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
            printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" NORMAL);
            bulkDelete();
            break;
        case 7:
            system("clear");
            printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
            printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" NORMAL);
            summaryReport();
            break;
        case 8:
            system("clear");
            printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
            printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" NORMAL);
            groupByType();
            break;
        case 9:
            system("clear");
            printf(BOLD "VEHICLE MANAGEMENT SYSTEM\n");
            printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" NORMAL);
            undoLast();
            break;
        default:
            if (choice < 0 || choice > 9)
            {
                printf("Invalid Choice!\n");
                break;
            }
        }
    } while (choice != 0);

    printf(BOLD "Exiting system");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout);
        usleep(3000);
    }
    printf(NORMAL);
    return 0;
}
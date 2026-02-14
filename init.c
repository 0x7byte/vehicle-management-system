#include "init.h"

Vehicle vehicles[MAX];
int vehicleCount = 0;

Undo undoHistory[UNDO_MAX];
int top = -1;

int findByID(int id)
{
    for (int i = 0; i < vehicleCount; i++)
        if (vehicles[i].id == id)
            return i;
    return -1;
}

void addVehicle()
{
    if (vehicleCount >= MAX)
    {
        printf("Storage full\n");
        return;
    }

    Vehicle temp;

    printf("ID[numeric ID]: ");
    scanf("%d", &temp.id);

    if (findByID(temp.id) != -1)
    {
        printf("Duplicate ID\n");
        return;
    }

    printf("Vehicle Type: ");
    scanf("%s", temp.vehicleType);

    printf("vehicle Model: ");
    scanf("%s", temp.vehicleModel);

    printf("Vehicle Brand: ");
    scanf("%s", temp.vehicleBrand);

    printf("Year of Manufacture: ");
    scanf("%d", &temp.year);

    printf("Engine Ccpacity [CC]: ");
    scanf("%d", &temp.engineCC);

    vehicles[vehicleCount] = temp;

    undoHistory[++top].action = ACTION_ADD;
    undoHistory[top].data = temp;
    undoHistory[top].index = vehicleCount;

    vehicleCount++;
    printf("Vehicle added\n");
}

// ShowOff the vab mere dekhano
void showVehicles()
{
    if (vehicleCount == 0)
    {
        printf("No vehicle/s found!\n");
        return;
    }

    for (int i = 0; i < vehicleCount; i++)
    {
        int tem = i;
        printf(BOLD "Vehicle NO: %3d\n", tem + 1);
        printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");

        printf("\nID:%d \nType:%s \nModel:%s \nBrand:%s \nYear:%d \nEngine Capacity:%d\n",
               vehicles[i].id,
               vehicles[i].vehicleType,
               vehicles[i].vehicleModel,
               vehicles[i].vehicleBrand,
               vehicles[i].year,
               vehicles[i].engineCC);
    }
    printf("\n" NORMAL);
}

// Update Info
void updateVehicle()
{
    int id;
    printf("Enter ID to update[numeric ID]: ");
    scanf("%d", &id);

    int i = findByID(id);
    if (i == -1)
    {
        printf("Vehicle not found\n");
        return;
    }

    undoHistory[++top].action = ACTION_UPDATE;
    undoHistory[top].data = vehicles[i];
    undoHistory[top].index = i;

    printf("New Brand: ");
    scanf("%s", vehicles[i].vehicleBrand);

    printf("New Year: ");
    scanf("%d", &vehicles[i].year);

    printf("New Engine CC: ");
    scanf("%d", &vehicles[i].engineCC);

    printf("Vehicle updated.\n");
}

// Delete the Legendary kich out
void deleteVehicle()
{
    int id;
    printf("Enter ID to delete[numeric ID]: ");
    scanf("%d", &id);

    int i = findByID(id);
    if (i == -1)
    {
        printf("Vehicle not found\n");
        return;
    }

    undoHistory[++top].action = ACTION_DELETE;
    undoHistory[top].data = vehicles[i];
    undoHistory[top].index = i;

    for (int j = i; j < vehicleCount - 1; j++)
        vehicles[j] = vehicles[j + 1];

    vehicleCount--;
    printf("Vehicle deleted\n");
}

// Search the khoja
int searchAny()
{
    printf(BOLD "Search the KHOJ\n");
    printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
    int ch;
    printf("1. Search by ID\n");
    printf("2. Search by text\n");
    printf("Choose option[1~2]: " NORMAL);
    scanf("%d", &ch);
    if (ch == 1)
    {
        int id;
        printf("Search input[numeric ID]: ");
        scanf("%d", &id);

        if (findByID(id) == -1)
        {
            printf("Vehicle not found!\n");
            return 0;
        }

        for (int i = 0; i < vehicleCount; i++)
            if (vehicles[i].id == id)
            {
                printf("Vehicle ID: %d\n", vehicles[i].id);
                printf("Vehicle Model: %s\n", vehicles[i].vehicleModel);
                printf("Vehicle Brand: %s\n", vehicles[i].vehicleBrand);
                printf("Vehicle Type: %s\n", vehicles[i].vehicleType);
                printf("Year of Manufacture: %d\n", vehicles[i].year);
                printf("Engine Capacity: %d CC\n", vehicles[i].engineCC);
            }
    }

    else if (ch == 2)
    {
        int cd = 0;
        char srcTxt[CIZE];
        printf("Search input: ");
        scanf("%s", srcTxt);

        for (int i = 0; i < vehicleCount; i++){
            if (strstr(vehicles[i].vehicleModel, srcTxt) || strstr(vehicles[i].vehicleBrand, srcTxt) || strstr(vehicles[i].vehicleType, srcTxt)){
                printf("ID:%d %s %s\n", vehicles[i].id, vehicles[i].vehicleModel, vehicles[i].vehicleBrand);
                cd++;
            }
        }
        if (cd == 0){
            printf("No data found!\n");
            return 0;
        }
    }
    else
        printf("Invalid choice!\n");
}

// One and only Legendary Bulk Remove
void bulkDelete()
{
    int year;
    printf("Delete vehicles older than year: ");
    scanf("%d", &year);

    for (int i = 0; i < vehicleCount;)
    {
        if (vehicles[i].year < year)
        {
            undoHistory[++top].action = ACTION_DELETE;
            undoHistory[top].data = vehicles[i];
            undoHistory[top].index = i;

            for (int j = i; j < vehicleCount - 1; j++)
                vehicles[j] = vehicles[j + 1];
            vehicleCount--;
        }
        else
        {
            i++;
        }
    }
}

// Summary
void summaryReport()
{
    if (vehicleCount == 0)
    {
        printf("No data.\n");
        return;
    }

    int sum = 0, minYear = 3000, maxYear = 0;

    for (int i = 0; i < vehicleCount; i++)
    {
        sum += vehicles[i].engineCC;
        if (vehicles[i].year < minYear)
            minYear = vehicles[i].year;
        if (vehicles[i].year > maxYear)
            maxYear = vehicles[i].year;
    }

    printf(NORMAL "Total Vehicle/s:%d\nAvg Engine Ccpacity:%d CC\nOldest:%d Newest:%d\n" BOLD,
           vehicleCount, sum / vehicleCount, minYear, maxYear);
}

// Grouping
int groupByType()
{
    char types[][6] = {"car", "bike", "bus", "truck"};
    printf("The legendary Grouping\n");
    printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
    if (vehicleCount == 0)
    {
        printf("No data found!\n");
        return 0;
    }

    for (int t = 0; t < 4; t++)
    {
        printf("\nGroup Type: %s\n", types[t]);
        for (int i = 0; i < vehicleCount; i++)
        {
            if (strcmp(vehicles[i].vehicleType, types[t]) == 0)
                printf("ID: %d\nModel: %s\n", vehicles[i].id, vehicles[i].vehicleModel);
        }
    }
}

// the undefeatable Undo :> by murad
void undoLast()
{
    if (top < 0)
    {
        printf("Nothing to undo! Do something YOU lazy man.\n");
        return;
    }

    Undo u = undoHistory[top--];

    if (u.action == ACTION_ADD)
    {
        vehicleCount--;
    }
    else if (u.action == ACTION_DELETE)
    {
        for (int i = vehicleCount; i > u.index; i--)
            vehicles[i] = vehicles[i - 1];
        vehicles[u.index] = u.data;
        vehicleCount++;
    }
    else if (u.action == ACTION_UPDATE)
    {
        vehicles[u.index] = u.data;
    }

    printf("Undo successful\n");
}
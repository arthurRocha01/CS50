#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    unsigned char buffer[512];

    if (file == NULL)
    {
        printf("Error opening the file\n");
        return 1;
    }

    FILE *img = NULL;
    size_t bytes_read;
    int count = 0;
    while(1)
    {
        bytes_read = fread(buffer, 1, sizeof(buffer), file);

        if (bytes_read == 0)
        {
            break;
        }

        if (bytes_read >= 3 && buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            char filename[12];
            snprintf(filename, sizeof(filename), "%03i.jpg", count++);
            img = fopen(filename, "wb");

            if (img == NULL)
            {
                printf("Error creating file: %s\n", filename);
                fclose(file);
                return 1;
            }
        }

        if (img != NULL)
        {
            size_t bytes_write = fwrite(buffer, 1, bytes_read, img);
            if (bytes_write != bytes_read)
            {
                printf("Error writing file\n");
                fclose(img);
                fclose(file);
                return 1;
            }
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }
    fclose(file);

    return 0;
}

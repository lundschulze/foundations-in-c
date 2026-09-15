#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    size_t count;
} IntBuffer;

static int buffer_create(IntBuffer *buffer, size_t count)
{
    buffer->data = malloc(count * sizeof *buffer->data);
    if (buffer->data == NULL)
    {
        buffer->count = 0;
        return 0;
    }
    buffer->count = count;
    return 1;
}

static void buffer_destroy(IntBuffer *buffer)
{
    free(buffer->data);
    buffer->data = NULL;
    buffer->count = 0;
}

int main(void)
{
    IntBuffer buffer = {.data = NULL, .count = 0};

    if (!buffer_create(&buffer, 3))
    {
        fputs("Could not create buffer.\n", stderr);
        return 1;
    }
    for (size_t index = 0; index < buffer.count; index++)
    {
        buffer.data[index] = (int)(index + 1) * 10;
        printf("%d\n", buffer.data[index]);
    }
    buffer_destroy(&buffer);
    printf("After destroy: count=%zu, empty=%s\n",
           buffer.count, buffer.data == NULL ? "yes" : "no");
    return 0;
}

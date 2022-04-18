#include "muduo/base/GzipFile.h"

int main()
{
    const char* filename = "/tmp/gzipfile_test.gz";
    ::unlink(filename);
    const char data[] = "123456789012345678901234567890123456789012345678901234567890\n";
    {
        muduo::GzipFile writer = muduo::GzipFile::openForAppend(filename);
        if (writer.valid())
        {
            off_t val;
            val = writer.tell();
            printf("[before] writer tell ret: %ld\n", val);
            int ret = writer.write(data);
            printf("[during] writer tell ret: %d\n", ret);
            val = writer.tell();
            printf("[after] writer tell ret: %ld\n", val);
        }
    }

    printf("testing reader\n");
    muduo::GzipFile reader = muduo::GzipFile::openForRead(filename);
    if (reader.valid())
    {
        char buf[256];
        off_t val;
        val = reader.tell();
        printf("[before] reader tell ret: %ld\n", val);
        int nr = reader.read(buf, sizeof buf);
        printf("read %d\n", nr);
        if (nr >= 0)
        {
            buf[nr] = '\0';
            printf("data %s", buf);
        }

        val = reader.tell();
        printf("[after] reader tell ret: %ld\n", val);
        if (strncmp(buf, data, strlen(data)) != 0)
        {
            printf("failed!!!\n");
            abort();
        }
        else
        {
            printf("PASSED\n");
        }
    }

    {
        muduo::GzipFile writer = muduo::GzipFile::openForWriteExclusive(filename);
        if (writer.valid() || errno != EEXIST)
        {
            printf("FAILED\n");
        }
    }
}
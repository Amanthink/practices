typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern struct_0 *g_403fd0;

unsigned long long * sub_401000(void)
{
    unsigned long long *v1;  // rax

    v1 = &g_403fd0->field_0;
    if (g_403fd0)
        v1 = g_403fd0();
    return v1;
}

extern unsigned long long g_403ff0;
extern unsigned long long g_403ff8;

void sub_401020(void)
{
    unsigned long v0;  // [bp-0x8]

    v0 = g_403ff0;
    goto g_403ff8;
}

void _start(unsigned long a0, unsigned long a1, long long a2)
{
    unsigned long v3;  // rax
    unsigned long v0;  // [bp+0x0]
    long long v1;  // [bp+0x0]
    unsigned long v2;  // [bp+0x8]

    v0 = v3;
    __libc_start_main(main, v1, &v2, 0, 0, a2, &v1, v3); /* do not return */
}

void sub_4010c1(void)
{
    [D] Unsupported jumpkind Ijk_SigTRAP at address 4198593()
}


void sub_4010d0(void)
{
    return;
}


unsigned long long sub_4010f9(void)
{
    return 0;
}

extern unsigned long long g_403fe0;
extern long long g_404038;
extern char g_404048;

void sub_401140(void)
{
    if (g_404048)
        return;
    if (g_403fe0)
        __cxa_finalize(g_404038);
    sub_4010d0();
    g_404048 = 1;
    return;
}

void sub_401180(void)
{
}

void sub_401189(char *a0, unsigned int a1)
{
    char v0;  // [bp-0x11]
    unsigned int j;  // [bp-0x10]
    int i;  // [bp-0xc]

    for (i = 0; i < a1 + (a1 >> 31) >> 1; i += 1)
    {
        v0 = a0[i];
        a0[i] = a0[1 + a1 + -1 * i];
        a0[1 + a1 + -1 * i] = v0;
    }
    for (j = 0; j < a1; j += 1)
    {
        a0[j] = a0[j] ^ 19;
    }
    return;
}

typedef struct FILE {
} FILE;

extern FILE *stdin;

unsigned int main(void)
{
    char v0[12];  // [bp-0xb8]
    char v1[20];  // [bp-0xac]
    char v2;  // [bp-0x98]
    unsigned int v3;  // [bp-0xc]

    strncpy(&v0, "n~\"-\"-L`$-\"l` | ", 16);
    strncpy(&v1, "` | l #l`$TPP`4r", 16);
    puts("=== ECHO CHAMBER ===");
    printf("Speak the truth: ");
    fgets(&v2, 128, stdin);
    (&v2)[strcspn(&v2, "\n")] = 0;
    v3 = strlen(&v2);
    sub_401189(&v2, v3);
    if (memcmp(&v2, &v0, 28))
    {
        puts("\nSignal Rejected");
        return 0;
    }
    puts("\nSignal Accepted");
    return 0;
}

void sub_40135c(void)
{
    return;
}


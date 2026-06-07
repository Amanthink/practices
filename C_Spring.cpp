int64_t sub_405301(char* arg1 @ rax)
{
    *arg1 -= arg1;
    /* undefined */
}

int64_t sub_405371(int64_t arg1, int32_t arg2, int32_t* arg3, void* arg4, int32_t arg5 @ rax, char* arg6 @ rbx)
{
    uint64_t rsi = arg2 + *arg3;
    *arg6 &= arg5;
    arg5 += 0x10;
    char* rax = arg5 + 0x20320320;
    *rsi = *rsi - rax;
    *rax += rax;
    *rax += *(&rax + 1);
    rax[0x41ff0000] += arg3;
    rax += *rax;
    *(arg4 + 2) += rax;
    *rax += rax;
    *rax += rax;
    *rax += rax;
    int64_t result = *0x408363;
    
    if (!result)
        return result;
    
    return result();
}

int64_t sub_4053aa(char* arg1 @ rax, int16_t arg2 @ rbx)
{
    *arg1 += arg1;
    *arg1 += arg1;
    *arg1 += arg1;
    *arg1 += arg1;
    *(&arg2 + 1) *= 2;
    /* jump -> *0x40838b */
}

int64_t sub_4053c3()
{
    /* jump -> *0x408393 */
}

int64_t sub_4053d3()
{
    /* jump -> *0x40839b */
}

int64_t sub_4053e3()
{
    /* jump -> *0x4083a3 */
}

int64_t sub_4053f3()
{
    /* jump -> *0x4083ab */
}

int64_t sub_4054fc()
{
    return sub_4053c3(0x40639b);
}

int64_t sub_405512()
{
    return sub_4053c3(0x4063b6);
}

int64_t sub_405528()
{
    int64_t var_53;
    __builtin_strcpy(&var_53, "opensesame");
    sub_4054fc();
    sub_405512();
    sub_4053d3(0x4063d1);
    void var_48;
    sub_4053e3(0x4063e2, &var_48, 0x4063e2);
    
    if (sub_4053f3(&var_48, &var_53, &var_53))
        sub_4053c3(0x40641c);
    else
    {
        sub_4053c3(0x4063e7);
        sub_4053c3(0x4063fb);
    }
    
    return 0;
}

int64_t sub_4055cb() __pure
{
    return;
}

int64_t sub_4057e6() __pure
{
    return;
}

void* _start(char* arg1, int32_t arg2, int32_t* arg3, int64_t arg4, char arg5, int64_t arg6, int64_t arg7 @ rbx)
{
    int64_t rax;
    int64_t var_8 = rax;
    int32_t* var_10 = arg3;
    sub_405a78();
    int64_t rbp;
    int64_t var_18 = rbp;
    void* result;
    int64_t rdx;
    int32_t* rsi_2;
    result = sub_40587d(arg3, arg1, arg3, 0, arg5, 0, -1, arg6, arg2 + arg1, arg3, arg4, arg7);
    *rsi_2;
    rdx = *(rsi_2 + 4);
    return result;
}

char* sub_40583f(int32_t* arg1, int64_t, int32_t arg3, int32_t arg4, int64_t arg5 @ rbp)
{
    char* result = arg1 + arg5;
    arg3 = *result;
    
    if (arg4 <= 5 || arg5 > -4)
    {
    label_405879:
        int32_t i;
        
        do
        {
            result = &result[1];
            *arg1 = arg3;
            i = arg4;
            arg4 -= 1;
            arg3 = *result;
            arg1 += 1;
        } while (i != 1);
    }
    else
    {
        int32_t i_2 = arg4 - 4;
        int32_t i_1;
        
        do
        {
            arg3 = *result;
            result = &result[4];
            i_1 = i_2;
            i_2 -= 4;
            *arg1 = arg3;
            arg1 = &arg1[1];
        } while (i_1 >= 4);
        arg4 = i_2 + 4;
        arg3 = *result;
        
        if (i_2 != 0xfffffffc)
            goto label_405879;
    }
    
    return result;
}

void* sub_40587d(char* arg1, char* arg2, char arg3, int32_t arg4, char arg5, int32_t arg6 @ rbx, int64_t arg7 @ rbp, int64_t arg8, int32_t arg9, int32_t* arg10, int64_t arg11, int64_t arg12)
{
    void* const __return_addr_1 = __return_addr;
    void* rsi_1;
    
    if (arg5 != 2)
        rsi_1 = arg1;
    else
    {
        while (true)
        {
            arg3 = *arg2;
            int32_t temp0_1 = arg6;
            int32_t temp1_1 = arg6;
            arg6 *= 2;
            bool c_1 = temp0_1 + temp1_1 < temp0_1;
            
            if (temp0_1 == -(temp1_1))
            {
                int32_t rbx = *arg2;
                char* temp2_1 = arg2;
                arg2 -= -4;
                bool c_2 = temp2_1 < -4;
                arg6 = rbx + rbx;
                c_1 = rbx + rbx < rbx || (c_2 && rbx + rbx == rbx);
                arg3 = *arg2;
            }
            
            if (c_1)
            {
                arg2 = &arg2[1];
                *arg1 = arg3;
                arg1 = &arg1[1];
            }
            else
            {
                int32_t rax_3;
                char rdx;
                int32_t* rsi;
                
                do
                {
                    int32_t rax_2;
                    int32_t rcx;
                    rax_2 = __return_addr_1();
                    rax_3 = rax_2 + rax_2;
                    int32_t temp5_1 = arg6;
                    int32_t temp6_1 = arg6;
                    arg6 *= 2;
                    c_1 = temp5_1 + temp6_1 < temp5_1;
                    
                    if (temp5_1 == -(temp6_1))
                    {
                        int32_t rbx_1 = *rsi;
                        int32_t* temp7_1 = rsi;
                        rsi -= -4;
                        bool c_3 = temp7_1 < -4;
                        arg6 = rbx_1 + rbx_1;
                        c_1 = rbx_1 + rbx_1 < rbx_1 || (c_3 && rbx_1 + rbx_1 == rbx_1);
                        rdx = *rsi;
                    }
                } while (!c_1);
                
                bool c_4 = rax_3 < 3;
                
                if (!c_4)
                {
                    int32_t rax_6 = (rax_3 - 3) << 8 | rdx;
                    rsi_1 = rsi + 1;
                    c_4 = false;
                    
                    if (rax_6 == 0xffffffff)
                        break;
                    
                    arg7 = rax_6 ^ 0xffffffff;
                }
                
                int32_t rcx_1;
                int64_t r11;
                rcx_1 = __return_addr_1();
                int32_t rax_9;
                int32_t rcx_2;
                int32_t rdx_2;
                int32_t* rdi;
                rax_9 = r11();
                int32_t rcx_3 = rcx_2 + rcx_2;
                
                if (!rcx_3)
                {
                    bool c_6 = rax_9 >= 0xfffffffe;
                    
                    do
                    {
                        int32_t rcx_4;
                        rax_9 = __return_addr_1();
                        rcx_3 = rcx_4 + rcx_4;
                        int32_t temp15_1 = arg6;
                        int32_t temp16_1 = arg6;
                        arg6 *= 2;
                        c_6 = temp15_1 + temp16_1 < temp15_1;
                        
                        if (temp15_1 == -(temp16_1))
                        {
                            int32_t rbx_2 = *arg2;
                            char* temp17_1 = arg2;
                            arg2 -= -4;
                            bool c_7 = temp17_1 < -4;
                            arg6 = rbx_2 + rbx_2;
                            c_6 = rbx_2 + rbx_2 < rbx_2 || (c_7 && rbx_2 + rbx_2 == rbx_2);
                        }
                    } while (!c_6);
                }
                
                arg4 = sub_40583f(rdi, arg2, rdx_2, rcx_3 + rax_9, arg7);
            }
        }
    }
    
    *arg10 = arg1 - arg9;
    return rsi_1 - arg8;
}

int64_t sub_4059fc(void* arg1 @ rbp)
{
    char* rax = syscall(sys_open {2}, __return_addr, 0);
    int32_t* rsi_1 = &__return_addr[0x13];
    uint64_t rax_2 = *(__return_addr + 0xf) & 0xfffffffe;
    uint64_t rdx = *rsi_1;
    void* rcx_1 = arg1 - 0xb - *(arg1 - 0xb);
    int32_t* var_20 = 0x22;
    int32_t* r10 = var_20;
    var_20 = rdx;
    int32_t* rsi_2 = var_20;
    var_20 = 3;
    int32_t* rdx_1 = var_20;
    var_20 = 9;
    int32_t* rax_4 = syscall(var_20, 0, rsi_2, rdx_1, r10, 0xffffffff, 0, rcx_1, rax, rax_2);
    var_20 = rax_4;
    int32_t* rdx_2 = var_20;
    var_20 = rsi_1;
    int32_t* rsi_3 = var_20;
    int32_t* rsi_4 = &rsi_3[1];
    var_20 = *rsi_3;
    int32_t* rsi_5 = &rsi_4[1];
    arg1(&rsi_5[1], *rsi_4, rdx_2, &var_20, *rsi_5);
    var_20 = 5;
    int32_t* rdx_3 = var_20;
    var_20 = 0xa;
    syscall(var_20, rax_4, rdx, rdx_3);
    /* jump -> rdx_2 */
}

int64_t sub_405a78()
{
    sub_4059fc(__return_addr);
    /* undefined */
}

int64_t sub_405a9f(int64_t arg1 @ rbp)
{
    /* jump -> arg1 */
}


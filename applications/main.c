
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include "rtconfig.h"
#include "stm32f10x.h"
#include "rtthread.h"



void thread1_entry(void *parameter)
{
    int i;
    while (1)
    {
        //gpio_output_bit_get(GPIOA,GPIO_PIN_0) ?         gpio_bit_reset(GPIOA, GPIO_PIN_0) :         gpio_bit_set(GPIOA, GPIO_PIN_0);
        rt_thread_mdelay(1000);
    }
    
}

void thread2_entry(void *param)
{
    int count = 0;
    while (1)
    {
        //gpio_output_bit_get(GPIOA,GPIO_PIN_1) ?         gpio_bit_reset(GPIOA, GPIO_PIN_1) :         gpio_bit_set(GPIOA, GPIO_PIN_1);
        rt_thread_mdelay(500);
    }
    
}

int main(void)
{
    

    if(0)
    {
        rt_thread_mdelay(50);
        lt8644_switch(4,4);
        lt8644_switch(5,5);
        lt8644_switch(6,6);
        lt8644_switch(7,7);

        lt8644_switch(3,3);
        lt8644_update();

    }

#if 1
    static struct rt_thread thread1;
    static rt_uint8_t stack[512];

    rt_thread_t thread2_ptr;
    rt_err_t result;

    result = rt_thread_init(&thread1,"thread1",thread1_entry,RT_NULL,&stack[0],sizeof(stack),30,10);

    if(RT_EOK == result)
        rt_thread_startup(&thread1);


    thread2_ptr = rt_thread_create("thread2",thread2_entry,RT_NULL,512,30,25);
    if(RT_NULL != thread2_ptr)
        rt_thread_startup(thread2_ptr);
#endif




    while (1)
    {

        //rt_kprintf("test\r\n");
        //rt_thread_mdelay(1000);


        //gpio_output_bit_get(GPIOA,GPIO_PIN_0) ?         gpio_bit_reset(GPIOA, GPIO_PIN_0) :         gpio_bit_set(GPIOA, GPIO_PIN_0);
        rt_thread_mdelay(1000);
    }
    /* USER CODE END 3 */
}

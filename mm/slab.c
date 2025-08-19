#include <xkernel/kernel.h>
#include <xkernel/init.h>
#include <xkernel/slab.h>
#include <xkernel/memory.h>


struct kmem_cache *kmem_cache_create(const char *name, unsigned int size,
			unsigned int align, slab_flags_t flags,
			void (*ctor)(void *))
{
    struct kmem_cache *s = NULL;
             
    // 加锁

    //


    // 关锁

    return NULL;
}


void __init kmem_cache_init(void){


}

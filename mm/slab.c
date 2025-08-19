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
    lock_acquire(slab_lock)

    //


    // 关锁
    lock_release(slab_lock)
    return NULL;
}


void __init kmem_cache_init(void){


}

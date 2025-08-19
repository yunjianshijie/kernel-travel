#ifndef __LINUX_SLAB_H__
#define __LINUX_SLAB_H__

#include <xkernel/kernel.h>
#include <xkernel/init.h>
#include <xkernel/list.h>
#include <xkernel/types.h>

#include <asm/numa.h>

struct kmem_cachestruct kmem_cache {
    
    size_t object_size;

    char name[1024];

    /* 伪 numn结构，只有一个numu结点 */
    struct list_head slabs_empty;
    struct list_head slabs_partial;
    struct list_head slabs_full;

    unsigned long free_objects;
    unsigned int free_limit;
    /*slab着色 */
    unsigned int colour_next; 
    // struct kmem_cache_node *node[MAX_NUMNODES];

};

struct slab {
    //反指kmem_cache 
    struct kmem_cache * slab_cache;

    struct list_head slab_list;
	void *freelist;	/* array of free object indexes */
	void *s_mem;	/* first object */

    int inuse; /*使用计数*/

    struct page * 
};


struct array_cache {
    unsigned int avail;
    unsigned int limit;
    unsigned int batchcount;
    unsigned int touched;
    // spinlock_t lock;
    void *entry[];
};


void *kmem_cache_alloc(struct kmem_cache *cachep, gfp_t flags);
void kmem_cache_free(struct kmem_cache *s, void *objp);
struct kmem_cache *kmem_cache_create(const char *name, unsigned int size,
			unsigned int align, slab_flags_t flags,
			void (*ctor)(void *));
void __init kmem_cache_init(void);

#endif
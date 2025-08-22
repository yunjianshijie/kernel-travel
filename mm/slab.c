#include <xkernel/kernel.h>
#include <xkernel/init.h>
#include <xkernel/slab.h>
#include <xkernel/memory.h>

#include <asm/page.h>

struct kmem_cache *kmem_cache;

struct lock *slab_lock;

#define OO_SHIFT 16
#define OO_MASK ((1 << OO_SHIFT) - 1)

static inline unsigned int order_objects(unsigned int order, unsigned int size)
{
    return ((unsigned int)PAGE_SIZE << order) / size;
}

static inline struct kmem_cache_order_objects oo_make(unsigned int order,
                                                      unsigned int size)
{
    struct kmem_cache_order_objects x = {
        (order << OO_SHIFT) + order_objects(order, size)};

    return x;
}
static inline unsigned int oo_order(struct kmem_cache_order_objects x)
{
    return x.x >> OO_SHIFT;
}

static inline unsigned int oo_objects(struct kmem_cache_order_objects x)
{
    return x.x & OO_MASK;
}

/*
 * Slab allocation and freeing
 */
static inline struct slab *alloc_slab_page(gfp_t flags, int node,
                                           struct kmem_cache_order_objects oo)
{
    struct slab *slab;
    unsigned int order = oo_order(oo);

    // 从伙伴系统中分配一页
    struct page *page = __alloc_pages(flags, order, -1);
    
    
    return slab;
}

static struct kmem_cache *create_cache(const char *name,
                                       unsigned int object_size, unsigned int align,
                                       slab_flags_t flags, unsigned int useroffset,
                                       unsigned int usersize, void (*ctor)(void *),
                                       struct kmem_cache *root_cache)
{
    struct kmem_cache *s;
    s->name = name;
    // s->size = s->object_size = object_size;
    // s->align = align;
    // s->ctor = ctor;

    return s;
}

struct kmem_cache *kmem_cache_create(const char *name, unsigned int size,
                                     unsigned int align, slab_flags_t flags,
                                     void (*ctor)(void *))
{
    struct kmem_cache *s = NULL;

    // 加锁
    lock_acquire(slab_lock);

    // 如果有同名的cache，就直接

    // 如果没有，就创建

    // 关锁
    lock_release(slab_lock);
    return NULL;
}

void __init kmem_cache_init(void)
{
    lock_init(slab_lock);
}

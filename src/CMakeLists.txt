cmake_minimum_required(VERSION 3.21)
project(stl30 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(stl30
        algo.h
        algobase.h
        alloc.h
        bvector.h
        defalloc.h
        deque.h
        function.h
        hash_map.h
        hash_set.h
        hashtable.h
        heap.h
        iterator.h
        list.h
        map.h
        multimap.h
        multiset.h
        pair.h
        pthread_alloc.h
        rope.h
        ropeimpl.h
        set.h
        slist.h
        stack.h
        stl_algo.h
        stl_algobase.h
        stl_alloc.h
        stl_bvector.h
        stl_config.h
        stl_construct.h
        stl_deque.h
        stl_function.h
        stl_hash_fun.h
        stl_hash_map.h
        stl_hash_set.h
        stl_hashtable.h
        stl_heap.h
        stl_iterator.h
        stl_list.h
        stl_map.h
        stl_multimap.h
        stl_multiset.h
        stl_numeric.h
        stl_pair.h
        stl_queue.h
        stl_raw_storage_iter.h
        stl_relops.h
        stl_rope.h
        stl_set.h
        stl_slist.h
        stl_stack.h
        stl_tempbuf.h
        stl_tree.h
        stl_uninitialized.h
        stl_vector.h
        tempbuf.h
        tree.h
        type_traits.h
        vector.h)

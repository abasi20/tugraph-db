﻿/**
 * Copyright 2022 AntGroup CO., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#include "fma-common/configuration.h"
#include "fma-common/logging.h"
#include "fma-common/unit_test_utils.h"
#include "fma-common/utils.h"

using namespace fma_common;

FMA_SET_TEST_PARAMS(Utils, "");

FMA_UNIT_TEST(Utils) {
    int a = 10;
    int olda = CompareAndSwap(&a, 10, 11);
    CHECK_EQ(olda, 10);
    CHECK_EQ(a, 11);
    olda = CompareAndSwap(&a, 10, 12);
    CHECK_EQ(olda, 11);
    CHECK_EQ(a, 11);

    double b = 1.0;
    double oldb = CompareAndSwap(&b, 1.0, 2.0);
    CHECK_EQ(oldb, 1.0);
    CHECK_EQ(b, 2.0);
    oldb = CompareAndSwap(&b, 1.0, 3.0);
    CHECK_EQ(oldb, 2.0);
    CHECK_EQ(b, 2.0);

    double *p = &b;
    double *oldp = CompareAndSwap(&p, &b, &oldb);
    CHECK_EQ(oldp, &b);
    CHECK_EQ(p, &oldb);

    CHECK_EQ(AtomicFetchAdd(&a, 10), 11);
    CHECK_EQ(a, 21);
    uint64_t la = 123;
    CHECK_EQ(AtomicFetchAdd(&la, (uint64_t)100), (uint64_t)123);
    CHECK_EQ(la, (uint64_t)223);

    double c = 1.0;
    AtomicAdd(&c, 2.0);
    CHECK_EQ(c, 3.0);

    float d = 3.0;
    AtomicAdd(&d, (float)4.0);
    CHECK_EQ(d, 7.0);

    void *ptr = (void *)0x1100048374234678;
    FMA_ASSERT(ToString(ptr) == "0x1100048374234678" || ToString(ptr) == "1100048374234678");

    return 0;
}


/*
 * (C) Copyright 2005- ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * In applying this licence, ECMWF does not waive the privileges and immunities granted to it by
 * virtue of its status as an intergovernmental organisation nor does it submit to any jurisdiction.
 */

#pragma once

#include "grib_accessor_class_gen.h"

class grib_accessor_bufr_elements_table_t : public grib_accessor_gen_t
{
public:
    grib_accessor_bufr_elements_table_t() :
        grib_accessor_gen_t() { class_name_ = "bufr_elements_table"; }
    grib_accessor* create_empty_accessor() override { return new grib_accessor_bufr_elements_table_t{}; }
    long get_native_type() override;
    int unpack_double(double* val, size_t* len) override;
    int unpack_long(long* val, size_t* len) override;
    int unpack_string(char*, size_t* len) override;
    int value_count(long*) override;
    void init(const long, grib_arguments*) override;

public:
    const char* dictionary_;
    const char* masterDir_;
    const char* localDir_;
};

int bufr_descriptor_is_marker(bufr_descriptor* d);
bufr_descriptor* accessor_bufr_elements_table_get_descriptor(grib_accessor* a, int code, int* err);

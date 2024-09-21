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

#include "grib_iterator_class_gen.h"

class grib_iterator_space_view_t : public grib_iterator_gen_t
{
public:
    grib_iterator_space_view_t()
    {
        class_name_ = "space_view";
    }

    int init(grib_handle*, grib_arguments*) override;
    int next(double *, double *, double *) override;
    int destroy() override;

private:
    double* lats_;
    double* lons_;
    long Nj_;
};


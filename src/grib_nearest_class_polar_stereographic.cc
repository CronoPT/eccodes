/*
 * (C) Copyright 2005- ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * In applying this licence, ECMWF does not waive the privileges and immunities granted to it by
 * virtue of its status as an intergovernmental organisation nor does it submit to any jurisdiction.
 */

#include "grib_api_internal.h"

/*
   This is used by make_class.pl

   START_CLASS_DEF
   CLASS      = nearest
   SUPER      = grib_nearest_class_gen
   IMPLEMENTS = init
   IMPLEMENTS = find;destroy
   MEMBERS    = double* lats
   MEMBERS    = int  lats_count
   MEMBERS    = double* lons
   MEMBERS    = int  lons_count
   MEMBERS    = double* distances
   MEMBERS    = int* k
   MEMBERS    = int* i
   MEMBERS    = int* j
   MEMBERS    = const char* Ni
   MEMBERS    = const char* Nj
   END_CLASS_DEF

 */

/* START_CLASS_IMP */

/*

Don't edit anything between START_CLASS_IMP and END_CLASS_IMP
Instead edit values between START_CLASS_DEF and END_CLASS_DEF
or edit "nearest.class" and rerun ./make_class.pl

*/


static void init_class              (grib_nearest_class*);

static int init               (grib_nearest* nearest,grib_handle* h,grib_arguments* args);
static int find(grib_nearest* nearest, grib_handle* h,double inlat, double inlon, unsigned long flags, double* outlats,double* outlons, double *values,double *distances, int *indexes,size_t *len);
static int destroy            (grib_nearest* nearest);

typedef struct grib_nearest_polar_stereographic{
  grib_nearest nearest;
    /* Members defined in gen */
    const char* values_key;
    const char* radius;
    int cargs;
    /* Members defined in polar_stereographic */
    double* lats;
    int  lats_count;
    double* lons;
    int  lons_count;
    double* distances;
    int* k;
    int* i;
    int* j;
    const char* Ni;
    const char* Nj;
} grib_nearest_polar_stereographic;

extern grib_nearest_class* grib_nearest_class_gen;

static grib_nearest_class _grib_nearest_class_polar_stereographic = {
    &grib_nearest_class_gen,                         /* super */
    "polar_stereographic",                         /* name */
    sizeof(grib_nearest_polar_stereographic),      /* size of instance */
    0,                              /* inited */
    &init_class,                    /* init_class */
    &init,                          /* constructor */
    &destroy,                       /* destructor */
    &find,                          /* find nearest */
};

grib_nearest_class* grib_nearest_class_polar_stereographic = &_grib_nearest_class_polar_stereographic;


static void init_class(grib_nearest_class* c)
{
}
/* END_CLASS_IMP */

static int init(grib_nearest* nearest, grib_handle* h, grib_arguments* args)
{
    grib_nearest_polar_stereographic* self = (grib_nearest_polar_stereographic*)nearest;
    self->Ni                               = grib_arguments_get_name(h, args, self->cargs++);
    self->Nj                               = grib_arguments_get_name(h, args, self->cargs++);
    self->i                                = (int*)grib_context_malloc(h->context, 2 * sizeof(int));
    self->j                                = (int*)grib_context_malloc(h->context, 2 * sizeof(int));
    return GRIB_SUCCESS;
}

static int find(grib_nearest* nearest, grib_handle* h,
                double inlat, double inlon, unsigned long flags,
                double* outlats, double* outlons,
                double* values, double* distances, int* indexes, size_t* len)
{
    grib_nearest_polar_stereographic* self = (grib_nearest_polar_stereographic*)nearest;
    return grib_nearest_find_generic(
        nearest, h, inlat, inlon, flags, /* inputs */

        self->values_key,   /* outputs to set the 'self' object */
        &(self->lats),
        &(self->lats_count),
        &(self->lons),
        &(self->lons_count),
        &(self->distances),

        outlats, outlons,  /* outputs of the find function */
        values, distances, indexes, len);
}

static int destroy(grib_nearest* nearest)
{
    grib_nearest_polar_stereographic* self = (grib_nearest_polar_stereographic*)nearest;
    grib_context* c = grib_context_get_default();

    if (self->lats)      grib_context_free(c, self->lats);
    if (self->lons)      grib_context_free(c, self->lons);
    if (self->i)         grib_context_free(c, self->i);
    if (self->j)         grib_context_free(c, self->j);
    if (self->k)         grib_context_free(c, self->k);
    if (self->distances) grib_context_free(c, self->distances);
    return GRIB_SUCCESS;
}

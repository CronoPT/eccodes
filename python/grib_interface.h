#ifndef GRIB_INTERFACE_H
#define GRIB_INTERFACE_H

int grib_c_read_any_from_file(int *fid, char *buffer, int *nbytes);
int grib_c_write_file(int *fid, char *buffer, int *nbytes);
int grib_c_read_file(int *fid, char *buffer, int *nbytes);
int grib_c_open_file(int *fid, char *name, char *op);
int grib_c_close_file(int *fid);
int grib_c_multi_support_on(void);
int grib_c_multi_support_off(void);
int grib_c_iterator_new(int *gid, int *iterid, int *mode);
int grib_c_iterator_next(int *iterid, double *lat, double *lon, double *value);
int grib_c_iterator_delete(int *iterid);
int grib_c_keys_iterator_new(int *gid, int *iterid, char *name_space);
int grib_c_keys_iterator_next(int *iterid);
int grib_c_keys_iterator_get_name(int *iterid, char *name, int len);
int grib_c_keys_iterator_rewind(int *kiter);
int grib_c_keys_iterator_delete(int *iterid);
int codes_c_bufr_keys_iterator_new(int *gid, int *iterid);
int codes_c_bufr_keys_iterator_next(int *iterid);
int codes_c_bufr_keys_iterator_get_name(int *iterid, char *name, int len);
int codes_c_bufr_keys_iterator_rewind(int *kiter);
int codes_c_bufr_keys_iterator_delete(int *iterid);

int grib_c_gribex_mode_on(void);
int grib_c_gribex_mode_off(void);
int grib_c_skip_computed(int *iterid);
int grib_c_skip_coded(int *iterid);
int grib_c_skip_edition_specific(int *iterid);
int grib_c_skip_duplicates(int *iterid);
int grib_c_skip_read_only(int *iterid);
int grib_c_skip_function(int *iterid);
int grib_c_new_from_message(int *gid, void *buffer, size_t *bufsize);
int grib_c_new_from_message_copy(int *gid, void *buffer, size_t *bufsize);
int grib_c_grib_new_from_samples(int *gid, char *name);
int grib_c_bufr_new_from_samples(int *gid, char *name);
int grib_c_clone(int *gidsrc, int *giddest);
int grib_c_copy_namespace(int *gidsrc, char *name, int *giddest);
int grib_c_count_in_file(FILE *f, int *n);
int grib_c_new_from_file(FILE *f, int *gid, int headers_only);
int grib_c_new_any_from_file(FILE *f, int headers_only,int *gid);
int grib_c_new_bufr_from_file(FILE *f, int headers_only,int *gid);
int grib_c_new_gts_from_file(FILE *f,int headers_only, int *gid);
int grib_c_new_metar_from_file(FILE* f,int headers_only, int* gid);
int grib_c_new_from_index(int *iid, int *gid);
int grib_c_index_new_from_file(char *file, char *keys, int *gid);
int grib_c_index_add_file(int* iid, char* file);
int grib_c_index_release(int *hid);
int grib_c_multi_release(int *hid);
int grib_c_release(int *hid);
int grib_c_dump(int *gid);
int grib_c_print(int *gid, char *key);
int grib_c_get_error_string(int *err, char *buf, int len);
int grib_c_get_size_int(int *gid, char *key, int *val);
int grib_c_get_size_long(int *gid, char *key, long *val);
int grib_c_index_get_size_int(int *gid, char *key, int *val);
int grib_c_index_get_size_long(int *gid, char *key, long *val);
int grib_c_get_int(int *gid, char *key, int *val);
int grib_c_get_long(int *gid, char *key, long *val);
int grib_c_get_double(int *gid, char *key, double *val);
int grib_c_get_int_array(int *gid, char *key, int *val, int *size);
int grib_c_get_long_array(int *gid, char *key, long *val, int *size);
int grib_c_index_get_string(int *gid, char *key, char *val, int *eachsize, int *size);
int grib_c_index_get_long(int *gid, char *key, long *val, int *size);
int grib_c_index_get_int(int *gid, char *key, int *val, int *size);
int grib_c_index_get_real8(int *gid, char *key, double *val, int *size);
int grib_c_set_int_array(int *gid, char *key, int *val, int *size);
int grib_c_set_long_array(int *gid, char *key, long *val, int *size);
int grib_c_set_int(int *gid, char *key, int *val);
int grib_c_set_long(int *gid, char *key, long *val);
int grib_c_set_missing(int *gid, char *key);
int grib_c_set_key_vals(int* gid, char* keyvals);
int grib_c_is_missing(int *gid, char *key, int *isMissing);
int grib_c_is_defined(int *gid, char *key, int *isDefined);
int grib_c_set_real4(int *gid, char *key, float *val);
int grib_c_get_real4_element(int *gid, char *key, int *index, float *val);
int grib_c_get_real4_elements(int *gid, char *key, int *index, float *val, int *size);
int grib_c_get_real4(int *gid, char *key, float *val);
int grib_c_get_real4_array(int *gid, char *key, float *val, int *size);
int grib_c_set_real4_array(int *gid, char *key, float *val, int *size);
int grib_c_index_select_real8(int *gid, char *key, double *val);
int grib_c_index_select_string(int *gid, char *key, char *val);
int grib_c_index_select_int(int *gid, char *key, int *val);
int grib_c_index_select_long(int *gid, char *key, long *val);
int grib_c_set_real8(int *gid, char *key, double *val);
int grib_c_get_real8(int *gid, char *key, double *val);
int grib_c_get_real8_element(int *gid, char *key, int *index, double *val);
int grib_c_get_real8_elements(int *gid, char *key, int *index, double *val, int *size);
int grib_c_find_nearest_four_single(int *gid, int *is_lsm, double *inlat, double *inlon, double *outlats, double *outlons, double *values, double *distances, int *indexes);
int grib_c_find_nearest_single(int *gid, int *is_lsm, double *inlats, double *inlons, double *outlats, double *outlons, double *values, double *distances, int *indexes);
int grib_c_find_nearest_multiple(int *gid, int *is_lsm, double *inlats, double *inlons, double *outlats, double *outlons, double *values, double *distances, int *indexes, int *npoints);
int grib_c_get_real8_array(int *gid, char *key, double *val, int *size);
int grib_c_set_real8_array(int *gid, char *key, double *val, int *size);
int grib_c_get_string(int *gid, char *key, char *val, size_t *lsize);
int grib_c_get_string_array(int* gid, char* key, char** val, size_t *lsize);
int grib_c_set_string(int *gid, char *key, char *val, int len2);
int grib_c_set_string_array(int *gid, char *key, const char **val);
int grib_c_get_data_real4(int *gid, float *lats, float *lons, float *values, size_t *size);
/*int grib_c_get_data_real8(int *gid, double *lats, double *lons, double *values, size_t *size);*/
int grib_c_get_message_size(int *gid, size_t *len);
int grib_c_get_message_offset(int *gid, size_t *len);
int grib_c_copy_message(int *gid, void *mess, size_t *len);
int grib_c_bufr_copy_data(int *msgid_src, int *msgid_dst);
void grib_c_check(int *err, char *call, char *str);
int grib_c_write(int *gid, FILE *f);
int grib_c_multi_new(int* mgid);
int grib_c_multi_write(int *gid, FILE *f);
int grib_c_multi_append(int *ingid, int *sec, int *mgid);
int grib_c_set_double_array(int* gid, char* key, double*val, int* size);
int grib_c_set_double(int* gid, char* key, double*val);
int grib_c_get_native_type(int* gid, char* key, int* type);
int grib_c_index_write(int* gid, char* file);
int grib_c_index_read(char* file, int* gid);
void no_fail_on_wrong_length(int flag);
long grib_c_get_api_version(void);
void grib_c_gts_header_on(void);
void grib_c_gts_header_off(void);
int grib_c_get_message(int *gid, const void **msg, size_t *size);
int grib_c_get_string_length(int* gid, char* key, size_t* val);
void grib_c_set_definitions_path(const char* path);
void grib_c_set_samples_path(const char* path);

#endif

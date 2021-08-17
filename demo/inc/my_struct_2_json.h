#ifdef __cplusplus
extern "C" {
#endif

cJSON *struct_to_json_addr_info_t(void* struct_obj);

void *json_to_struct_addr_info_t(cJSON* json_obj);

cJSON *struct_to_json_student_info_t(void* struct_obj);

void *json_to_struct_student_info_t(cJSON* json_obj);
    
#ifdef __cplusplus
}
#endif /* end of __cplusplus */
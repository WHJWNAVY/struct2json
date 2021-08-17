#include "mc_usr_def.h"
#include "my_struct_2_json.inc"
#include "my_struct_2_json.h"


#ifdef __cplusplus
extern "C" {
#endif
    
#if 0
typedef struct addr_info_s
{
	uint32_t id;
	char name[MAX_NAME_LEN];
	char addr[MAX_ADDR_LEN];
} addr_info_t;
#endif
cJSON *struct_to_json_addr_info_t(void* struct_obj)
{
	s2j_create_json_obj(json_obj_);
	addr_info_t *struct_obj_ = (addr_info_t *)struct_obj;
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, id);
	s2j_json_set_basic_element(json_obj_, struct_obj_, string, name);
	s2j_json_set_basic_element(json_obj_, struct_obj_, string, addr);
	return json_obj_;
}

void *json_to_struct_addr_info_t(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_, addr_info_t);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, id);
	s2j_struct_get_basic_element(struct_obj_,json_obj, string, name);
	s2j_struct_get_basic_element(struct_obj_,json_obj, string, addr);
	return struct_obj_;
}

#if 0
typedef struct student_info_s
{
	uint32_t id;
	uint32_t age;
	uint32_t height;
	uint32_t weight;
	char name[MAX_NAME_LEN];
	addr_info_t home[MAX_HOME_LEN];
	addr_info_t school[MAX_SCHOOL_LEN];
} student_info_t;
#endif
cJSON *struct_to_json_student_info_t(void* struct_obj)
{
	s2j_create_json_obj(json_obj_);
	student_info_t *struct_obj_ = (student_info_t *)struct_obj;
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, id);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, age);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, height);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, weight);
	s2j_json_set_basic_element(json_obj_, struct_obj_, string, name);
	s2j_json_set_struct_array_element_by_func(json_obj_, struct_obj_, addr_info_t,home,MAX_HOME_LEN);
	s2j_json_set_struct_array_element_by_func(json_obj_, struct_obj_, addr_info_t,school,MAX_SCHOOL_LEN);
	return json_obj_;
}

void *json_to_struct_student_info_t(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_, student_info_t);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, id);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, age);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, height);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, weight);
	s2j_struct_get_basic_element(struct_obj_,json_obj, string, name);
	s2j_struct_get_struct_array_element_by_func(struct_obj_, json_obj, addr_info_t,home);
	s2j_struct_get_struct_array_element_by_func(struct_obj_, json_obj, addr_info_t,school);
	return struct_obj_;
}
#ifdef DEBUGS2J 
 int s2j_test(void)
 {
	
    char file_name[] = "struct_defination.json";
    FILE *fp;

    fp = fopen(file_name, "w");
    if (NULL == fp) return 1;
    fprintf(fp,"{\n\t\"struct\": [\n\t\t{\n\t\t\t\"type\": \"void*\",\n\t\t\t\"value\": null\n\t\t}"); 

    TEST_S2J_STRUCT(addr_info_t, 0 , fp);
    TEST_S2J_STRUCT(student_info_t, 0 , fp);
    
    fprintf(fp,"\n\t]\n}");
    fclose(fp);
    return 0;
}



 int s2j_test2(void)
 {

    char file_name[] = "struct_defination.json";
    FILE *fp;

    fp = fopen(file_name, "rb");
    if (NULL == fp) return 1;

   fseek(fp,0L,SEEK_END);
   int flen=ftell(fp);
   char* p=(char *)malloc(flen+1);
   if(p==NULL)
   {
        fclose(fp);
        return 0;
    }
    fseek(fp,0L,SEEK_SET);
    fread(p,flen,1,fp);
    p[flen]=0;

    printf("\nstruct_defination.json:\n%s\n",p);

    cJSON *json_obj =cJSON_Parse(p);
    CHECK_NOT_NULL(json_obj)
    cJSON *json_struct = cJSON_GetObjectItem(json_obj, "struct");
    CHECK_NOT_NULL(json_struct)

    int array_size = cJSON_GetArraySize(json_struct);
    printf("\nsize:\n%d\n",array_size);
    int i = 0; \

    TEST_S2J_JSON(addr_info_t, array_size);
    TEST_S2J_JSON(student_info_t, array_size);
    
    fclose(fp);
    free(p);
    return 0;
}


#endif// DEBUGS2J

#ifdef __cplusplus
}
#endif /* end of __cplusplus */
/*GENERATED BY TOOLS/CONCAT.PY (DO NOT EDIT)*/
#ifndef WAX_STD_TEXT
#define WAX_STD_TEXT
const char* TEXT_std_cs = "public static V w_mapGet<K,V>(Dictionary<K,V> map, K key, V defaultValue) {V v;if (map.TryGetValue(key,out v)){return v;}return defaultValue;}\n"
"public static bool w_BOOL(int x){return x!=0;}\n"
"public static int w_INT(bool x){return x?1:0;}\n"
"public static int w_NOT(int x){return (x==0)?1:0;}\n"
"public static int w_AND(int x, int y){return ((x!=0) && (y!=0))?1:0;}\n"
"public static int w_OR(int x, int y){return ((x!=0) || (y!=0))?1:0;}\n";
const char* TEXT_std_py = "def w_arr_remove(a,i,n):del a[i:i+n]\n"
"def w_slice(a,i,n):return a[i:i+n]\n"
"def w_map_get(m,k,d):\n"
"    try:return m[k]\n"
"    except:return d\n"
"def w_map_remove(m,k):\n"
"    try:del m[k]\n"
"    except:pass\n";
const char* TEXT_std_c = "#ifndef WAX_STD\n"
"#define WAX_STD\n"
"#include <stdlib.h>\n"
"#include <stdio.h>\n"
"#include <string.h>\n"
"#include <stdarg.h>\n"
"#include <math.h>\n"
"#define W_MIN(a,b) (((a)<(b))?(a):(b))\n"
"#define W_MAX(a,b) (((a)>(b))?(a):(b))\n"
"typedef struct w_arr_st {void* data;size_t len;size_t cap;size_t elem_size;} w_arr_t;\n"
"w_arr_t* w_arr_new_impl(int elem_size){w_arr_t* arr = (w_arr_t*)malloc(sizeof(w_arr_t));arr->elem_size = elem_size;arr->len = 0;arr->cap = 16;arr->data = malloc((arr->cap)*elem_size);return arr;}\n"
"w_arr_t* w_arr_new_ints(int count,...){va_list vals;w_arr_t* arr = (w_arr_t*)malloc(sizeof(w_arr_t));arr->elem_size = sizeof(int);arr->len = count;arr->cap = count;arr->data = malloc((arr->cap)*arr->elem_size);va_start(vals, count);for (int i = 0; i < count; i++) {((int*)arr->data)[i]=va_arg(vals, int);}va_end(vals);return arr;}\n"
"w_arr_t* w_arr_new_flts(int count,...){va_list vals;w_arr_t* arr = (w_arr_t*)malloc(sizeof(w_arr_t));arr->elem_size = sizeof(float);arr->len = count;arr->cap = count;arr->data = malloc((arr->cap)*arr->elem_size);va_start(vals, count);for (int i = 0; i < count; i++) {((float*)arr->data)[i]=(float)va_arg(vals, double);}va_end(vals);return arr;}\n"
"w_arr_t* w_arr_new_strs(int count,...){va_list vals;w_arr_t* arr = (w_arr_t*)malloc(sizeof(w_arr_t));arr->elem_size = sizeof(char*);arr->len = count;arr->cap = count;arr->data = malloc((arr->cap)*arr->elem_size);va_start(vals, count);for (int i = 0; i < count; i++) {((char**)arr->data)[i]=(char*)va_arg(vals, char*);}va_end(vals);return arr;}\n"
"int* w_vec_new_ints(int count,...){va_list vals;int* vec = (int*)malloc(sizeof(int)*count);va_start(vals, count);for (int i = 0; i < count; i++) {vec[i]=va_arg(vals, int);}va_end(vals);return vec;}\n"
"float* w_vec_new_flts(int count,...){va_list vals;float* vec = (float*)malloc(sizeof(float)*count);va_start(vals, count);for (int i = 0; i < count; i++) {vec[i]=(float)va_arg(vals, double);}va_end(vals);return vec;}\n"
"char** w_vec_new_strs(int count,...){va_list vals;char** vec = (char**)malloc(sizeof(char*)*count);va_start(vals, count);for (int i = 0; i < count; i++) {vec[i]=va_arg(vals, char*);}va_end(vals);return vec;}\n"
"#define w_arr_new(type)         (w_arr_new_impl(sizeof(type)))\n"
"#define w_arr_get(type,arr,i  ) (((type *)((arr)->data))[(i)])\n"
"#define w_arr_set(type,arr,i,x) (((type *)((arr)->data))[(i)]=(x))\n"
"void w_arr_insert_impl(w_arr_t* arr,int i) {if ((arr)->len >= (arr)->cap){(arr)->cap = (arr)->cap+W_MAX(4,(arr)->cap/2);(arr)->data = realloc((arr)->data, (arr)->elem_size*((arr)->cap));}if ((i) < (arr)->len){memmove((char*)((arr)->data)+((i)+1)*(arr)->elem_size,(char*)((arr)->data)+(i)*(arr)->elem_size,((arr)->len-(i))*(arr)->elem_size );}(arr)->len++;}\n"
"#define w_arr_insert(type,arr,i,x) { type tmp__x_ = x; int tmp__i_ = i; w_arr_t* tmp__a_ = arr; w_arr_insert_impl((tmp__a_),(tmp__i_)); (((type *)((tmp__a_)->data))[(tmp__i_)]=(tmp__x_)); }\n"
"void w_arr_remove(w_arr_t* arr,int i,int n) {memmove((char*)((arr)->data)+(i)*(arr)->elem_size,(char*)((arr)->data)+((i)+(n))*(arr)->elem_size,((arr->len)-(i)+(n))*(arr)->elem_size );(arr)->len-=(n);}\n"
"w_arr_t* w_arr_slice(w_arr_t*arr,int i,int n) {w_arr_t* brr = (w_arr_t*)malloc(sizeof(w_arr_t));brr->elem_size = (arr)->elem_size;brr->len = n;brr->cap = n;brr->data = malloc((brr->cap)*(brr->elem_size));memcpy((char*)(brr->data), (char*)((arr)->data) + (i), (n)*((arr)->elem_size));return brr;}\n"
"#define W_NUM_MAP_SLOTS 64\n"
"typedef struct w_slot_st {int keylen;void* key;int64_t data;struct w_slot_st* next;} w_slot_t;\n"
"typedef struct w_map_st {char key_is_ptr;size_t len;w_slot_t* slots[W_NUM_MAP_SLOTS];} w_map_t;\n"
"w_map_t* w_map_new(char key_is_ptr){w_map_t* map = (w_map_t*)malloc(sizeof(w_map_t));map->key_is_ptr = key_is_ptr;for (int i = 0; i < W_NUM_MAP_SLOTS; i++){map->slots[i] = NULL;}map->len = 0;return map;}\n"
"int w_map_hash(void* ptr, size_t len){int x = 0;for (int i = 0; i < len; i++){char y = *((char*)((char*)ptr+i));x ^= y;}x %= W_NUM_MAP_SLOTS;return x;}\n"
"void w_map_set(w_map_t* map, int64_t key, int64_t data){int keylen;void* keyptr;if (map->key_is_ptr){keylen = strlen((char*)key);keyptr = (char*)key;}else{keylen = sizeof(key);keyptr = &key;}int k = w_map_hash(keyptr,keylen);w_slot_t* it = map->slots[k];while (it){if (keylen == it->keylen){if (memcmp(it->key,keyptr,keylen)==0){it->data = data;return;}}it = it -> next;}w_slot_t* nxt = map->slots[k];w_slot_t* slot = (w_slot_t*)malloc(sizeof(w_slot_t));slot->key = malloc(keylen);memcpy(slot->key,keyptr,keylen);slot->data=data;slot->next = nxt;slot->keylen = keylen;map->slots[k] = slot;map->len++;}\n"
"int64_t w_map_get(w_map_t* map, int64_t key){int keylen;void* keyptr;if (map->key_is_ptr){keylen = strlen((char*)key);keyptr = (char*)key;}else{keylen = sizeof(key);keyptr = &key;}int k = w_map_hash(keyptr,keylen);w_slot_t* it = map->slots[k];while (it){if (keylen == it->keylen){if (memcmp(it->key,keyptr,keylen)==0){return it->data;}}it = it -> next;}return 0;}\n"
"void w_map_remove(w_map_t* map, int64_t key){int keylen;void* keyptr;if (map->key_is_ptr){keylen = strlen((char*)key);keyptr = (char*)key;}else{keylen = sizeof(key);keyptr = &key;}int k = w_map_hash(keyptr,keylen);w_slot_t* it = map->slots[k];w_slot_t* prev = NULL;while (it){if (keylen == it->keylen){if (memcmp(it->key,keyptr,keylen)==0){if (prev){prev->next = it->next;}else{map->slots[k] = it->next;}free(it->key);free(it);return;}}prev = it;it = it -> next;}return;}\n"
"int w_reinterp_f2i(float x){return (int)((int *)&x);}\n"
"typedef struct {char data[32];} w_shortstr_t;\n"
"w_shortstr_t w_int2str(int x){w_shortstr_t str;sprintf(str.data, \"%d\", x);return str;}\n"
"w_shortstr_t w_flt2str(float x){w_shortstr_t str;sprintf(str.data, \"%g\", x);return str;}\n"
"char* w_str_new(char* x){int l = strlen(x);char* str = malloc(l);strncpy(str,x,l);str[l] = 0;return str;}\n"
"char* w_str_cat(char* x, char* y){int l0 = strlen(x);int l1 = strlen(y);x = (char*)realloc(x,l0+l1+1);memcpy(x+l0,y,l1);x[l0+l1] = 0;return x;}\n"
"char* w_str_add(char* x, int y){char c = (char)y;int l = strlen(x);x = (char*)realloc(x,l+2);x[l] = c;x[l+1]=0;return x;}\n"
"char* w_str_cpy(char* x, int i, int l){char* y = (char*)malloc(l+1);memcpy(y,x+i,l);y[l] = 0;return y;}\n"
"void w_free(void* x){if (x){free(x);}}\n"
"void w_free_arr(w_arr_t* x){if (x){free(x->data);free(x);}}\n"
"void w_free_map(w_map_t* map){if (!map){return;}for (int i = 0; i < W_NUM_MAP_SLOTS; i++){w_slot_t* it = map->slots[i];while (it){w_slot_t* nxt = it->next;free(it->key);free(it);it = nxt;}}free(map);}\n"
"#endif\n";
const char* TEXT_std_java = "public static <T> void w_arrRemove(ArrayList<T> a, int i, int n){a.subList(i,i+n).clear();}\n"
"public static <T> ArrayList<T> w_arrSlice(ArrayList<T> a, int i, int n){return new ArrayList<T>(a.subList(i,i+n));}\n"
"public static String w_strSlice(String a, int i, int n){return a.substring(i,i+n);}\n"
"public static <K,V> V w_mapGet(HashMap<K,V> map, K key, V defaultValue) {V v;return (((v = map.get(key)) != null) || map.containsKey(key))? v: defaultValue;}\n"
"public static boolean w_BOOL(int x){return x!=0;}\n"
"public static int w_INT(boolean x){return x?1:0;}\n"
"public static int w_NOT(int x){return (x==0)?1:0;}\n"
"public static int w_AND(int x, int y){return ((x!=0) && (y!=0))?1:0;}\n"
"public static int w_OR(int x, int y){return ((x!=0) || (y!=0))?1:0;}\n";
const char* TEXT_std_ts = "\n";
const char* TEXT_std_cpp = "template <typename T>\n"
"inline void w_arr_insert (std::vector<T>* arr, int i, T x){arr->insert(arr->begin()+i,x);}\n"
"template <typename T>\n"
"inline void w_arr_remove (std::vector<T>* arr, int i, int n){arr->remove(arr->begin()+i,arr->begin()+i+n);}\n"
"template <typename T>\n"
"inline std::vector<T>* w_arr_slice (std::vector<T>* arr, int i, int n){return new std::vector<T>(arr->begin()+i,arr->begin()+i+n);}\n"
"template <typename K, typename V>\n"
"inline V w_map_get (std::map<K,V>* m, K k, V defau){typename std::map<K,V>::iterator it = m->find(k);if (it != m->end()){return it->second;}return defau;}\n"
"template <typename T, std::size_t N>\n"
"inline std::array<T,N>* w_vec_init (T v){std::array<T,N>* vec = new std::array<T,N>;vec->fill(v);return vec;}\n";
const char* TEXT_math_wax = "(@pragma once)  (extern acos   (param x float) (result float)) (extern asin   (param x float) (result float)) (extern atan   (param x float) (result float)) (extern cos    (param x float) (result float)) (extern cosh   (param x float) (result float)) (extern sin    (param x float) (result float)) (extern sinh   (param x float) (result float)) (extern tan    (param x float) (result float)) (extern tanh   (param x float) (result float)) (extern exp    (param x float) (result float)) (extern log    (param x float) (result float)) (extern sqrt   (param x float) (result float)) (extern ceil   (param x float) (result float)) (extern floor  (param x float) (result float)) (extern fabs   (param x float) (result float)) (extern round  (param x float) (result float)) (extern atan2  (param x float) (param y float) (result float)) (extern pow    (param x float) (param y float) (result float)) (extern fmax   (param x float) (param y float) (result float)) (extern fmin   (param x float) (param y float) (result float)) (extern abs    (param x int) (result int)) (extern random (result float)) (extern INFINITY float)   (@if TARGET_C 1 	(asm \"#define random() ((float)rand()/RAND_MAX)\n\") )  (@if TARGET_CPP 1 	(asm \"#define random() ((float)rand()/RAND_MAX)\n\") )  (@if TARGET_JAVA 1 	(asm \"public static float fabs(float x){return Math.abs(x);}\n\") 	(asm \"public static float fmin(float x, float y){return Math.min(x,y);}\n\") 	(asm \"public static float fmax(float x, float y){return Math.max(x,y);}\n\") 	(asm \"public static final float INFINITY = Float.POSITIVE_INFINITY;\n\") )  (@if TARGET_TS 1 	(asm \"const acos  = Math.acos  ;\n\") 	(asm \"const asin  = Math.asin  ;\n\") 	(asm \"const atan  = Math.atan  ;\n\") 	(asm \"const cos   = Math.cos   ;\n\") 	(asm \"const sin   = Math.sin   ;\n\") 	(asm \"const tan   = Math.tan   ;\n\") 	(asm \"const exp   = Math.exp   ;\n\") 	(asm \"const log   = Math.log   ;\n\") 	(asm \"const sqrt  = Math.sqrt  ;\n\") 	(asm \"const ceil  = Math.ceil  ;\n\") 	(asm \"const floor = Math.floor ;\n\") 	(asm \"const fabs  = Math.abs   ;\n\") 	(asm \"const fmin  = Math.min   ;\n\") 	(asm \"const fmax  = Math.max   ;\n\") 	(asm \"const atan2 = Math.atan2 ;\n\") 	(asm \"const pow   = Math.pow   ;\n\") 	(asm \"const abs   = Math.abs   ;\n\") 	(asm \"const round = Math.round ;\n\") 	(asm \"const random= Math.random;\n\") 	(asm \"const INFINITY = Infinity;\n\") 	(asm \"// @ts-ignore\n\") 	(asm \"const sinh  = Math.sinh ;\n\") 	(asm \"// @ts-ignore\n\") 	(asm \"const cosh  = Math.cosh ;\n\") 	(asm \"// @ts-ignore\n\") 	(asm \"const tanh  = Math.tanh ;\n\") )  (@if TARGET_PY 1 	(asm \"from math import *\n\") 	(asm \"from random import random\n\") 	(asm \"INFINITY = float('inf')\n\") 	(asm \"fabs = abs\n\") 	(asm \"fmin = min\n\") 	(asm \"fmax = max\n\")  )   (@if TARGET_CS 1 	(asm \"public static Func<double,double> acos     = Math.Acos   ;\n\") 	(asm \"public static Func<double,double> asin     = Math.Asin   ;\n\") 	(asm \"public static Func<double,double> atan     = Math.Atan   ;\n\") 	(asm \"public static Func<double,double> cos      = Math.Cos    ;\n\") 	(asm \"public static Func<double,double> sin      = Math.Sin    ;\n\") 	(asm \"public static Func<double,double> tan      = Math.Tan    ;\n\") 	(asm \"public static Func<double,double> exp      = Math.Exp    ;\n\") 	(asm \"public static Func<double,double> log      = Math.Log    ;\n\") 	(asm \"public static Func<double,double> sqrt     = Math.Sqrt   ;\n\") 	(asm \"public static Func<double,double> ceil     = Math.Ceiling;\n\") 	(asm \"public static Func<double,double> floor    = Math.Floor  ;\n\") 	(asm \"public static Func<double,double> fabs     = Math.Abs    ;\n\") 	(asm \"public static Func<double,double> sinh     = Math.Sinh   ;\n\") 	(asm \"public static Func<double,double> cosh     = Math.Cosh   ;\n\") 	(asm \"public static Func<double,double> tanh     = Math.Tanh   ;\n\") 	(asm \"public static Func<double,double> round    = Math.Round  ;\n\") 	(asm \"public static Func<int,int> abs            = Math.Abs    ;\n\") 	(asm \"public static Func<double,double,double> atan2 = Math.Atan2 ;\n\") 	(asm \"public static Func<double,double,double> pow   = Math.Pow   ;\n\") 	(asm \"public static Func<double,double,double> fmin  = Math.Min   ;\n\") 	(asm \"public static Func<double,double,double> fmax  = Math.Max   ;\n\") 	(asm \"public static float INFINITY = Single.PositiveInfinity;\n\") 	(asm \"public static Random w_RNG = new Random();\n\") 	(asm \"public static float random(){ return (float)w_RNG.NextDouble(); }\n\")  )\n";

#endif

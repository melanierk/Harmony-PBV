/* Type information for GCC.
   Copyright (C) 2004, 2007, 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* This file is machine generated.  Do not edit.  */

/* Allocators for known structs and unions.  */

#define ggc_alloc_tree2WeakVH() ((struct tree2WeakVH *)(ggc_internal_alloc_stat (sizeof (struct tree2WeakVH) MEM_STAT_INFO)))
#define ggc_alloc_cleared_tree2WeakVH() ((struct tree2WeakVH *)(ggc_internal_cleared_alloc_stat (sizeof (struct tree2WeakVH) MEM_STAT_INFO)))
#define ggc_alloc_vec_tree2WeakVH(n) ((struct tree2WeakVH *)(ggc_internal_vec_alloc_stat (sizeof (struct tree2WeakVH), n MEM_STAT_INFO)))
#define ggc_alloc_cleared_vec_tree2WeakVH(n) ((struct tree2WeakVH *)(ggc_internal_cleared_vec_alloc_stat (sizeof (struct tree2WeakVH), n MEM_STAT_INFO)))
#define ggc_alloc_zone_tree2WeakVH(z) ((struct tree2WeakVH *)(ggc_internal_zone_alloc_stat (z, sizeof (struct tree2WeakVH) MEM_STAT_INFO)))
#define ggc_alloc_zone_cleared_tree2WeakVH(z) ((struct tree2WeakVH *)(ggc_internal_zone_cleared_alloc_stat (z, sizeof (struct tree2WeakVH) MEM_STAT_INFO)))
#define ggc_alloc_zone_vec_tree2WeakVH(n, z) ((struct tree2WeakVH *)(ggc_internal_zone_vec_alloc_stat (z, sizeof (struct tree2WeakVH), n MEM_STAT_INFO)))
#define ggc_alloc_zone_cleared_vec_tree2WeakVH(n, z) ((struct tree2WeakVH *)(ggc_internal_zone_cleared_vec_alloc_stat (z, sizeof (struct tree2WeakVH), n MEM_STAT_INFO)))
#define ggc_alloc_tree2Type() ((struct tree2Type *)(ggc_internal_alloc_stat (sizeof (struct tree2Type) MEM_STAT_INFO)))
#define ggc_alloc_cleared_tree2Type() ((struct tree2Type *)(ggc_internal_cleared_alloc_stat (sizeof (struct tree2Type) MEM_STAT_INFO)))
#define ggc_alloc_vec_tree2Type(n) ((struct tree2Type *)(ggc_internal_vec_alloc_stat (sizeof (struct tree2Type), n MEM_STAT_INFO)))
#define ggc_alloc_cleared_vec_tree2Type(n) ((struct tree2Type *)(ggc_internal_cleared_vec_alloc_stat (sizeof (struct tree2Type), n MEM_STAT_INFO)))
#define ggc_alloc_zone_tree2Type(z) ((struct tree2Type *)(ggc_internal_zone_alloc_stat (z, sizeof (struct tree2Type) MEM_STAT_INFO)))
#define ggc_alloc_zone_cleared_tree2Type(z) ((struct tree2Type *)(ggc_internal_zone_cleared_alloc_stat (z, sizeof (struct tree2Type) MEM_STAT_INFO)))
#define ggc_alloc_zone_vec_tree2Type(n, z) ((struct tree2Type *)(ggc_internal_zone_vec_alloc_stat (z, sizeof (struct tree2Type), n MEM_STAT_INFO)))
#define ggc_alloc_zone_cleared_vec_tree2Type(n, z) ((struct tree2Type *)(ggc_internal_zone_cleared_vec_alloc_stat (z, sizeof (struct tree2Type), n MEM_STAT_INFO)))
#define ggc_alloc_tree2int() ((struct tree2int *)(ggc_internal_alloc_stat (sizeof (struct tree2int) MEM_STAT_INFO)))
#define ggc_alloc_cleared_tree2int() ((struct tree2int *)(ggc_internal_cleared_alloc_stat (sizeof (struct tree2int) MEM_STAT_INFO)))
#define ggc_alloc_vec_tree2int(n) ((struct tree2int *)(ggc_internal_vec_alloc_stat (sizeof (struct tree2int), n MEM_STAT_INFO)))
#define ggc_alloc_cleared_vec_tree2int(n) ((struct tree2int *)(ggc_internal_cleared_vec_alloc_stat (sizeof (struct tree2int), n MEM_STAT_INFO)))
#define ggc_alloc_zone_tree2int(z) ((struct tree2int *)(ggc_internal_zone_alloc_stat (z, sizeof (struct tree2int) MEM_STAT_INFO)))
#define ggc_alloc_zone_cleared_tree2int(z) ((struct tree2int *)(ggc_internal_zone_cleared_alloc_stat (z, sizeof (struct tree2int) MEM_STAT_INFO)))
#define ggc_alloc_zone_vec_tree2int(n, z) ((struct tree2int *)(ggc_internal_zone_vec_alloc_stat (z, sizeof (struct tree2int), n MEM_STAT_INFO)))
#define ggc_alloc_zone_cleared_vec_tree2int(n, z) ((struct tree2int *)(ggc_internal_zone_cleared_vec_alloc_stat (z, sizeof (struct tree2int), n MEM_STAT_INFO)))

/* Allocators for known typedefs.  */

/* GC marker procedures.  */
/* macros and declarations */
#define gt_ggc_m_11tree2WeakVH(X) do { \
  if (X != NULL) gt_ggc_mx_tree2WeakVH (X);\
  } while (0)
extern void gt_ggc_mx_tree2WeakVH (void *);
#define gt_ggc_m_9tree2Type(X) do { \
  if (X != NULL) gt_ggc_mx_tree2Type (X);\
  } while (0)
extern void gt_ggc_mx_tree2Type (void *);
#define gt_ggc_m_8tree2int(X) do { \
  if (X != NULL) gt_ggc_mx_tree2int (X);\
  } while (0)
extern void gt_ggc_mx_tree2int (void *);
#define gt_ggc_m_15c_inline_static(X) do { \
  if (X != NULL) gt_ggc_mx_c_inline_static (X);\
  } while (0)
extern void gt_ggc_mx_c_inline_static (void *);
#define gt_ggc_m_24VEC_c_goto_bindings_p_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_c_goto_bindings_p_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_c_goto_bindings_p_gc (void *);
#define gt_ggc_m_15c_goto_bindings(X) do { \
  if (X != NULL) gt_ggc_mx_c_goto_bindings (X);\
  } while (0)
extern void gt_ggc_mx_c_goto_bindings (void *);
#define gt_ggc_m_7c_scope(X) do { \
  if (X != NULL) gt_ggc_mx_c_scope (X);\
  } while (0)
extern void gt_ggc_mx_c_scope (void *);
#define gt_ggc_m_9c_binding(X) do { \
  if (X != NULL) gt_ggc_mx_c_binding (X);\
  } while (0)
extern void gt_ggc_mx_c_binding (void *);
#define gt_ggc_m_12c_label_vars(X) do { \
  if (X != NULL) gt_ggc_mx_c_label_vars (X);\
  } while (0)
extern void gt_ggc_mx_c_label_vars (void *);
#define gt_ggc_m_8c_parser(X) do { \
  if (X != NULL) gt_ggc_mx_c_parser (X);\
  } while (0)
extern void gt_ggc_mx_c_parser (void *);
#define gt_ggc_m_20VEC_ivarref_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_ivarref_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_ivarref_entry_gc (void *);
#define gt_ggc_m_22VEC_prot_list_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_prot_list_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_prot_list_entry_gc (void *);
#define gt_ggc_m_19VEC_msgref_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_msgref_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_msgref_entry_gc (void *);
#define gt_ggc_m_23VEC_ident_data_tuple_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_ident_data_tuple_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_ident_data_tuple_gc (void *);
#define gt_ggc_m_15interface_tuple(X) do { \
  if (X != NULL) gt_ggc_mx_interface_tuple (X);\
  } while (0)
extern void gt_ggc_mx_interface_tuple (void *);
#define gt_ggc_m_17string_descriptor(X) do { \
  if (X != NULL) gt_ggc_mx_string_descriptor (X);\
  } while (0)
extern void gt_ggc_mx_string_descriptor (void *);
#define gt_ggc_m_9imp_entry(X) do { \
  if (X != NULL) gt_ggc_mx_imp_entry (X);\
  } while (0)
extern void gt_ggc_mx_imp_entry (void *);
#define gt_ggc_m_16hashed_attribute(X) do { \
  if (X != NULL) gt_ggc_mx_hashed_attribute (X);\
  } while (0)
extern void gt_ggc_mx_hashed_attribute (void *);
#define gt_ggc_m_12hashed_entry(X) do { \
  if (X != NULL) gt_ggc_mx_hashed_entry (X);\
  } while (0)
extern void gt_ggc_mx_hashed_entry (void *);
#define gt_ggc_m_19VEC_method_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_method_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_method_entry_gc (void *);
#define gt_ggc_m_14type_assertion(X) do { \
  if (X != NULL) gt_ggc_mx_type_assertion (X);\
  } while (0)
extern void gt_ggc_mx_type_assertion (void *);
#define gt_ggc_m_18treetreehash_entry(X) do { \
  if (X != NULL) gt_ggc_mx_treetreehash_entry (X);\
  } while (0)
extern void gt_ggc_mx_treetreehash_entry (void *);
#define gt_ggc_m_5CPool(X) do { \
  if (X != NULL) gt_ggc_mx_CPool (X);\
  } while (0)
extern void gt_ggc_mx_CPool (void *);
#define gt_ggc_m_3JCF(X) do { \
  if (X != NULL) gt_ggc_mx_JCF (X);\
  } while (0)
extern void gt_ggc_mx_JCF (void *);
#define gt_ggc_m_17module_htab_entry(X) do { \
  if (X != NULL) gt_ggc_mx_module_htab_entry (X);\
  } while (0)
extern void gt_ggc_mx_module_htab_entry (void *);
#define gt_ggc_m_13binding_level(X) do { \
  if (X != NULL) gt_ggc_mx_binding_level (X);\
  } while (0)
extern void gt_ggc_mx_binding_level (void *);
#define gt_ggc_m_23VEC_pending_noexcept_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_pending_noexcept_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_pending_noexcept_gc (void *);
#define gt_ggc_m_9opt_stack(X) do { \
  if (X != NULL) gt_ggc_mx_opt_stack (X);\
  } while (0)
extern void gt_ggc_mx_opt_stack (void *);
#define gt_ggc_m_27VEC_pending_redefinition_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_pending_redefinition_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_pending_redefinition_gc (void *);
#define gt_ggc_m_19VEC_pending_weak_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_pending_weak_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_pending_weak_gc (void *);
#define gt_ggc_m_11align_stack(X) do { \
  if (X != NULL) gt_ggc_mx_align_stack (X);\
  } while (0)
extern void gt_ggc_mx_align_stack (void *);
#define gt_ggc_m_18VEC_tree_gc_vec_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_tree_gc_vec_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_tree_gc_vec_gc (void *);
#define gt_ggc_m_19VEC_const_char_p_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_const_char_p_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_const_char_p_gc (void *);
#define gt_ggc_m_21pending_abstract_type(X) do { \
  if (X != NULL) gt_ggc_mx_pending_abstract_type (X);\
  } while (0)
extern void gt_ggc_mx_pending_abstract_type (void *);
#define gt_ggc_m_15VEC_tree_int_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_tree_int_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_tree_int_gc (void *);
#define gt_ggc_m_9cp_parser(X) do { \
  if (X != NULL) gt_ggc_mx_cp_parser (X);\
  } while (0)
extern void gt_ggc_mx_cp_parser (void *);
#define gt_ggc_m_17cp_parser_context(X) do { \
  if (X != NULL) gt_ggc_mx_cp_parser_context (X);\
  } while (0)
extern void gt_ggc_mx_cp_parser_context (void *);
#define gt_ggc_m_34VEC_cp_unparsed_functions_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_cp_unparsed_functions_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_cp_unparsed_functions_entry_gc (void *);
#define gt_ggc_m_27VEC_cp_default_arg_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_cp_default_arg_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_cp_default_arg_entry_gc (void *);
#define gt_ggc_m_8cp_lexer(X) do { \
  if (X != NULL) gt_ggc_mx_cp_lexer (X);\
  } while (0)
extern void gt_ggc_mx_cp_lexer (void *);
#define gt_ggc_m_15VEC_cp_token_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_cp_token_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_cp_token_gc (void *);
#define gt_ggc_m_10tree_check(X) do { \
  if (X != NULL) gt_ggc_mx_tree_check (X);\
  } while (0)
extern void gt_ggc_mx_tree_check (void *);
#define gt_ggc_m_14constexpr_call(X) do { \
  if (X != NULL) gt_ggc_mx_constexpr_call (X);\
  } while (0)
extern void gt_ggc_mx_constexpr_call (void *);
#define gt_ggc_m_16constexpr_fundef(X) do { \
  if (X != NULL) gt_ggc_mx_constexpr_fundef (X);\
  } while (0)
extern void gt_ggc_mx_constexpr_fundef (void *);
#define gt_ggc_m_22VEC_deferred_access_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_deferred_access_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_deferred_access_gc (void *);
#define gt_ggc_m_10spec_entry(X) do { \
  if (X != NULL) gt_ggc_mx_spec_entry (X);\
  } while (0)
extern void gt_ggc_mx_spec_entry (void *);
#define gt_ggc_m_16pending_template(X) do { \
  if (X != NULL) gt_ggc_mx_pending_template (X);\
  } while (0)
extern void gt_ggc_mx_pending_template (void *);
#define gt_ggc_m_21VEC_incomplete_var_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_incomplete_var_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_incomplete_var_gc (void *);
#define gt_ggc_m_21named_label_use_entry(X) do { \
  if (X != NULL) gt_ggc_mx_named_label_use_entry (X);\
  } while (0)
extern void gt_ggc_mx_named_label_use_entry (void *);
#define gt_ggc_m_28VEC_deferred_access_check_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_deferred_access_check_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_deferred_access_check_gc (void *);
#define gt_ggc_m_18sorted_fields_type(X) do { \
  if (X != NULL) gt_ggc_mx_sorted_fields_type (X);\
  } while (0)
extern void gt_ggc_mx_sorted_fields_type (void *);
#define gt_ggc_m_18VEC_tree_pair_s_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_tree_pair_s_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_tree_pair_s_gc (void *);
#define gt_ggc_m_17named_label_entry(X) do { \
  if (X != NULL) gt_ggc_mx_named_label_entry (X);\
  } while (0)
extern void gt_ggc_mx_named_label_entry (void *);
#define gt_ggc_m_32VEC_qualified_typedef_usage_t_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_qualified_typedef_usage_t_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_qualified_typedef_usage_t_gc (void *);
#define gt_ggc_m_14cp_token_cache(X) do { \
  if (X != NULL) gt_ggc_mx_cp_token_cache (X);\
  } while (0)
extern void gt_ggc_mx_cp_token_cache (void *);
#define gt_ggc_m_11saved_scope(X) do { \
  if (X != NULL) gt_ggc_mx_saved_scope (X);\
  } while (0)
extern void gt_ggc_mx_saved_scope (void *);
#define gt_ggc_m_16cxx_int_tree_map(X) do { \
  if (X != NULL) gt_ggc_mx_cxx_int_tree_map (X);\
  } while (0)
extern void gt_ggc_mx_cxx_int_tree_map (void *);
#define gt_ggc_m_23VEC_cp_label_binding_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_cp_label_binding_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_cp_label_binding_gc (void *);
#define gt_ggc_m_23VEC_cp_class_binding_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_cp_class_binding_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_cp_class_binding_gc (void *);
#define gt_ggc_m_24VEC_cxx_saved_binding_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_cxx_saved_binding_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_cxx_saved_binding_gc (void *);
#define gt_ggc_m_16cp_binding_level(X) do { \
  if (X != NULL) gt_ggc_mx_cp_binding_level (X);\
  } while (0)
extern void gt_ggc_mx_cp_binding_level (void *);
#define gt_ggc_m_11cxx_binding(X) do { \
  if (X != NULL) gt_ggc_mx_cxx_binding (X);\
  } while (0)
extern void gt_ggc_mx_cxx_binding (void *);
#define gt_ggc_m_15binding_entry_s(X) do { \
  if (X != NULL) gt_ggc_mx_binding_entry_s (X);\
  } while (0)
extern void gt_ggc_mx_binding_entry_s (void *);
#define gt_ggc_m_15binding_table_s(X) do { \
  if (X != NULL) gt_ggc_mx_binding_table_s (X);\
  } while (0)
extern void gt_ggc_mx_binding_table_s (void *);
#define gt_ggc_m_11tinst_level(X) do { \
  if (X != NULL) gt_ggc_mx_tinst_level (X);\
  } while (0)
extern void gt_ggc_mx_tinst_level (void *);
#define gt_ggc_m_14VEC_tinfo_s_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_tinfo_s_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_tinfo_s_gc (void *);
#define gt_ggc_m_18gnat_binding_level(X) do { \
  if (X != NULL) gt_ggc_mx_gnat_binding_level (X);\
  } while (0)
extern void gt_ggc_mx_gnat_binding_level (void *);
#define gt_ggc_m_9elab_info(X) do { \
  if (X != NULL) gt_ggc_mx_elab_info (X);\
  } while (0)
extern void gt_ggc_mx_elab_info (void *);
#define gt_ggc_m_10stmt_group(X) do { \
  if (X != NULL) gt_ggc_mx_stmt_group (X);\
  } while (0)
extern void gt_ggc_mx_stmt_group (void *);
#define gt_ggc_m_16VEC_parm_attr_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_parm_attr_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_parm_attr_gc (void *);
#define gt_ggc_m_11parm_attr_d(X) do { \
  if (X != NULL) gt_ggc_mx_parm_attr_d (X);\
  } while (0)
extern void gt_ggc_mx_parm_attr_d (void *);
#define gt_ggc_m_23VEC_inline_summary_t_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_inline_summary_t_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_inline_summary_t_gc (void *);
#define gt_ggc_m_22VEC_size_time_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_size_time_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_size_time_entry_gc (void *);
#define gt_ggc_m_16VEC_condition_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_condition_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_condition_gc (void *);
#define gt_ggc_m_17lto_in_decl_state(X) do { \
  if (X != NULL) gt_ggc_mx_lto_in_decl_state (X);\
  } while (0)
extern void gt_ggc_mx_lto_in_decl_state (void *);
#define gt_ggc_m_22VEC_ipa_edge_args_t_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_ipa_edge_args_t_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_ipa_edge_args_t_gc (void *);
#define gt_ggc_m_20lto_symtab_entry_def(X) do { \
  if (X != NULL) gt_ggc_mx_lto_symtab_entry_def (X);\
  } while (0)
extern void gt_ggc_mx_lto_symtab_entry_def (void *);
#define gt_ggc_m_20ssa_operand_memory_d(X) do { \
  if (X != NULL) gt_ggc_mx_ssa_operand_memory_d (X);\
  } while (0)
extern void gt_ggc_mx_ssa_operand_memory_d (void *);
#define gt_ggc_m_13scev_info_str(X) do { \
  if (X != NULL) gt_ggc_mx_scev_info_str (X);\
  } while (0)
extern void gt_ggc_mx_scev_info_str (void *);
#define gt_ggc_m_24VEC_mem_addr_template_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_mem_addr_template_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_mem_addr_template_gc (void *);
#define gt_ggc_m_26gimple_type_leader_entry_s(X) do { \
  if (X != NULL) gt_ggc_mx_gimple_type_leader_entry_s (X);\
  } while (0)
extern void gt_ggc_mx_gimple_type_leader_entry_s (void *);
#define gt_ggc_m_17gimple_seq_node_d(X) do { \
  if (X != NULL) gt_ggc_mx_gimple_seq_node_d (X);\
  } while (0)
extern void gt_ggc_mx_gimple_seq_node_d (void *);
#define gt_ggc_m_9type_hash(X) do { \
  if (X != NULL) gt_ggc_mx_type_hash (X);\
  } while (0)
extern void gt_ggc_mx_type_hash (void *);
#define gt_ggc_m_16string_pool_data(X) do { \
  if (X != NULL) gt_ggc_mx_string_pool_data (X);\
  } while (0)
extern void gt_ggc_mx_string_pool_data (void *);
#define gt_ggc_m_23temp_slot_address_entry(X) do { \
  if (X != NULL) gt_ggc_mx_temp_slot_address_entry (X);\
  } while (0)
extern void gt_ggc_mx_temp_slot_address_entry (void *);
#define gt_ggc_m_15throw_stmt_node(X) do { \
  if (X != NULL) gt_ggc_mx_throw_stmt_node (X);\
  } while (0)
extern void gt_ggc_mx_throw_stmt_node (void *);
#define gt_ggc_m_21VEC_eh_landing_pad_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_eh_landing_pad_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_eh_landing_pad_gc (void *);
#define gt_ggc_m_16VEC_eh_region_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_eh_region_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_eh_region_gc (void *);
#define gt_ggc_m_10eh_catch_d(X) do { \
  if (X != NULL) gt_ggc_mx_eh_catch_d (X);\
  } while (0)
extern void gt_ggc_mx_eh_catch_d (void *);
#define gt_ggc_m_16eh_landing_pad_d(X) do { \
  if (X != NULL) gt_ggc_mx_eh_landing_pad_d (X);\
  } while (0)
extern void gt_ggc_mx_eh_landing_pad_d (void *);
#define gt_ggc_m_11eh_region_d(X) do { \
  if (X != NULL) gt_ggc_mx_eh_region_d (X);\
  } while (0)
extern void gt_ggc_mx_eh_region_d (void *);
#define gt_ggc_m_22cached_dw_loc_list_def(X) do { \
  if (X != NULL) gt_ggc_mx_cached_dw_loc_list_def (X);\
  } while (0)
extern void gt_ggc_mx_cached_dw_loc_list_def (void *);
#define gt_ggc_m_17call_arg_loc_node(X) do { \
  if (X != NULL) gt_ggc_mx_call_arg_loc_node (X);\
  } while (0)
extern void gt_ggc_mx_call_arg_loc_node (void *);
#define gt_ggc_m_16var_loc_list_def(X) do { \
  if (X != NULL) gt_ggc_mx_var_loc_list_def (X);\
  } while (0)
extern void gt_ggc_mx_var_loc_list_def (void *);
#define gt_ggc_m_12var_loc_node(X) do { \
  if (X != NULL) gt_ggc_mx_var_loc_node (X);\
  } while (0)
extern void gt_ggc_mx_var_loc_node (void *);
#define gt_ggc_m_20VEC_die_arg_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_die_arg_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_die_arg_entry_gc (void *);
#define gt_ggc_m_16limbo_die_struct(X) do { \
  if (X != NULL) gt_ggc_mx_limbo_die_struct (X);\
  } while (0)
extern void gt_ggc_mx_limbo_die_struct (void *);
#define gt_ggc_m_20VEC_macinfo_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_macinfo_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_macinfo_entry_gc (void *);
#define gt_ggc_m_20VEC_pubname_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_pubname_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_pubname_entry_gc (void *);
#define gt_ggc_m_19VEC_dw_attr_node_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_dw_attr_node_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_dw_attr_node_gc (void *);
#define gt_ggc_m_27VEC_dw_line_info_table_p_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_dw_line_info_table_p_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_dw_line_info_table_p_gc (void *);
#define gt_ggc_m_25dw_line_info_table_struct(X) do { \
  if (X != NULL) gt_ggc_mx_dw_line_info_table_struct (X);\
  } while (0)
extern void gt_ggc_mx_dw_line_info_table_struct (void *);
#define gt_ggc_m_25VEC_dw_line_info_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_dw_line_info_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_dw_line_info_entry_gc (void *);
#define gt_ggc_m_18comdat_type_struct(X) do { \
  if (X != NULL) gt_ggc_mx_comdat_type_struct (X);\
  } while (0)
extern void gt_ggc_mx_comdat_type_struct (void *);
#define gt_ggc_m_25dw_ranges_by_label_struct(X) do { \
  if (X != NULL) gt_ggc_mx_dw_ranges_by_label_struct (X);\
  } while (0)
extern void gt_ggc_mx_dw_ranges_by_label_struct (void *);
#define gt_ggc_m_16dw_ranges_struct(X) do { \
  if (X != NULL) gt_ggc_mx_dw_ranges_struct (X);\
  } while (0)
extern void gt_ggc_mx_dw_ranges_struct (void *);
#define gt_ggc_m_25VEC_deferred_locations_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_deferred_locations_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_deferred_locations_gc (void *);
#define gt_ggc_m_17VEC_dw_fde_ref_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_dw_fde_ref_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_dw_fde_ref_gc (void *);
#define gt_ggc_m_24reg_saved_in_data_struct(X) do { \
  if (X != NULL) gt_ggc_mx_reg_saved_in_data_struct (X);\
  } while (0)
extern void gt_ggc_mx_reg_saved_in_data_struct (void *);
#define gt_ggc_m_17dw_cfi_row_struct(X) do { \
  if (X != NULL) gt_ggc_mx_dw_cfi_row_struct (X);\
  } while (0)
extern void gt_ggc_mx_dw_cfi_row_struct (void *);
#define gt_ggc_m_15dwarf_file_data(X) do { \
  if (X != NULL) gt_ggc_mx_dwarf_file_data (X);\
  } while (0)
extern void gt_ggc_mx_dwarf_file_data (void *);
#define gt_ggc_m_20indirect_string_node(X) do { \
  if (X != NULL) gt_ggc_mx_indirect_string_node (X);\
  } while (0)
extern void gt_ggc_mx_indirect_string_node (void *);
#define gt_ggc_m_17VEC_dw_cfi_ref_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_dw_cfi_ref_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_dw_cfi_ref_gc (void *);
#define gt_ggc_m_18dw_loc_list_struct(X) do { \
  if (X != NULL) gt_ggc_mx_dw_loc_list_struct (X);\
  } while (0)
extern void gt_ggc_mx_dw_loc_list_struct (void *);
#define gt_ggc_m_19dw_loc_descr_struct(X) do { \
  if (X != NULL) gt_ggc_mx_dw_loc_descr_struct (X);\
  } while (0)
extern void gt_ggc_mx_dw_loc_descr_struct (void *);
#define gt_ggc_m_13dw_cfi_struct(X) do { \
  if (X != NULL) gt_ggc_mx_dw_cfi_struct (X);\
  } while (0)
extern void gt_ggc_mx_dw_cfi_struct (void *);
#define gt_ggc_m_8typeinfo(X) do { \
  if (X != NULL) gt_ggc_mx_typeinfo (X);\
  } while (0)
extern void gt_ggc_mx_typeinfo (void *);
#define gt_ggc_m_22VEC_alias_set_entry_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_alias_set_entry_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_alias_set_entry_gc (void *);
#define gt_ggc_m_17alias_set_entry_d(X) do { \
  if (X != NULL) gt_ggc_mx_alias_set_entry_d (X);\
  } while (0)
extern void gt_ggc_mx_alias_set_entry_d (void *);
#define gt_ggc_m_24constant_descriptor_tree(X) do { \
  if (X != NULL) gt_ggc_mx_constant_descriptor_tree (X);\
  } while (0)
extern void gt_ggc_mx_constant_descriptor_tree (void *);
#define gt_ggc_m_15cgraph_asm_node(X) do { \
  if (X != NULL) gt_ggc_mx_cgraph_asm_node (X);\
  } while (0)
extern void gt_ggc_mx_cgraph_asm_node (void *);
#define gt_ggc_m_25cgraph_indirect_call_info(X) do { \
  if (X != NULL) gt_ggc_mx_cgraph_indirect_call_info (X);\
  } while (0)
extern void gt_ggc_mx_cgraph_indirect_call_info (void *);
#define gt_ggc_m_11cgraph_edge(X) do { \
  if (X != NULL) gt_ggc_mx_cgraph_edge (X);\
  } while (0)
extern void gt_ggc_mx_cgraph_edge (void *);
#define gt_ggc_m_24VEC_ipa_replace_map_p_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_ipa_replace_map_p_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_ipa_replace_map_p_gc (void *);
#define gt_ggc_m_15ipa_replace_map(X) do { \
  if (X != NULL) gt_ggc_mx_ipa_replace_map (X);\
  } while (0)
extern void gt_ggc_mx_ipa_replace_map (void *);
#define gt_ggc_m_18lto_file_decl_data(X) do { \
  if (X != NULL) gt_ggc_mx_lto_file_decl_data (X);\
  } while (0)
extern void gt_ggc_mx_lto_file_decl_data (void *);
#define gt_ggc_m_16VEC_ipa_ref_t_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_ipa_ref_t_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_ipa_ref_t_gc (void *);
#define gt_ggc_m_12varpool_node(X) do { \
  if (X != NULL) gt_ggc_mx_varpool_node (X);\
  } while (0)
extern void gt_ggc_mx_varpool_node (void *);
#define gt_ggc_m_11cgraph_node(X) do { \
  if (X != NULL) gt_ggc_mx_cgraph_node (X);\
  } while (0)
extern void gt_ggc_mx_cgraph_node (void *);
#define gt_ggc_m_18VEC_basic_block_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_basic_block_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_basic_block_gc (void *);
#define gt_ggc_m_14gimple_bb_info(X) do { \
  if (X != NULL) gt_ggc_mx_gimple_bb_info (X);\
  } while (0)
extern void gt_ggc_mx_gimple_bb_info (void *);
#define gt_ggc_m_11rtl_bb_info(X) do { \
  if (X != NULL) gt_ggc_mx_rtl_bb_info (X);\
  } while (0)
extern void gt_ggc_mx_rtl_bb_info (void *);
#define gt_ggc_m_11VEC_edge_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_edge_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_edge_gc (void *);
#define gt_ggc_m_13VEC_loop_p_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_loop_p_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_loop_p_gc (void *);
#define gt_ggc_m_4loop(X) do { \
  if (X != NULL) gt_ggc_mx_loop (X);\
  } while (0)
extern void gt_ggc_mx_loop (void *);
#define gt_ggc_m_9loop_exit(X) do { \
  if (X != NULL) gt_ggc_mx_loop_exit (X);\
  } while (0)
extern void gt_ggc_mx_loop_exit (void *);
#define gt_ggc_m_13nb_iter_bound(X) do { \
  if (X != NULL) gt_ggc_mx_nb_iter_bound (X);\
  } while (0)
extern void gt_ggc_mx_nb_iter_bound (void *);
#define gt_ggc_m_24types_used_by_vars_entry(X) do { \
  if (X != NULL) gt_ggc_mx_types_used_by_vars_entry (X);\
  } while (0)
extern void gt_ggc_mx_types_used_by_vars_entry (void *);
#define gt_ggc_m_17language_function(X) do { \
  if (X != NULL) gt_ggc_mx_language_function (X);\
  } while (0)
extern void gt_ggc_mx_language_function (void *);
#define gt_ggc_m_5loops(X) do { \
  if (X != NULL) gt_ggc_mx_loops (X);\
  } while (0)
extern void gt_ggc_mx_loops (void *);
#define gt_ggc_m_18control_flow_graph(X) do { \
  if (X != NULL) gt_ggc_mx_control_flow_graph (X);\
  } while (0)
extern void gt_ggc_mx_control_flow_graph (void *);
#define gt_ggc_m_9eh_status(X) do { \
  if (X != NULL) gt_ggc_mx_eh_status (X);\
  } while (0)
extern void gt_ggc_mx_eh_status (void *);
#define gt_ggc_m_11stack_usage(X) do { \
  if (X != NULL) gt_ggc_mx_stack_usage (X);\
  } while (0)
extern void gt_ggc_mx_stack_usage (void *);
#define gt_ggc_m_20initial_value_struct(X) do { \
  if (X != NULL) gt_ggc_mx_initial_value_struct (X);\
  } while (0)
extern void gt_ggc_mx_initial_value_struct (void *);
#define gt_ggc_m_11frame_space(X) do { \
  if (X != NULL) gt_ggc_mx_frame_space (X);\
  } while (0)
extern void gt_ggc_mx_frame_space (void *);
#define gt_ggc_m_17rtx_constant_pool(X) do { \
  if (X != NULL) gt_ggc_mx_rtx_constant_pool (X);\
  } while (0)
extern void gt_ggc_mx_rtx_constant_pool (void *);
#define gt_ggc_m_18VEC_temp_slot_p_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_temp_slot_p_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_temp_slot_p_gc (void *);
#define gt_ggc_m_13dw_fde_struct(X) do { \
  if (X != NULL) gt_ggc_mx_dw_fde_struct (X);\
  } while (0)
extern void gt_ggc_mx_dw_fde_struct (void *);
#define gt_ggc_m_9temp_slot(X) do { \
  if (X != NULL) gt_ggc_mx_temp_slot (X);\
  } while (0)
extern void gt_ggc_mx_temp_slot (void *);
#define gt_ggc_m_9gimple_df(X) do { \
  if (X != NULL) gt_ggc_mx_gimple_df (X);\
  } while (0)
extern void gt_ggc_mx_gimple_df (void *);
#define gt_ggc_m_23VEC_call_site_record_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_call_site_record_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_call_site_record_gc (void *);
#define gt_ggc_m_18call_site_record_d(X) do { \
  if (X != NULL) gt_ggc_mx_call_site_record_d (X);\
  } while (0)
extern void gt_ggc_mx_call_site_record_d (void *);
#define gt_ggc_m_14sequence_stack(X) do { \
  if (X != NULL) gt_ggc_mx_sequence_stack (X);\
  } while (0)
extern void gt_ggc_mx_sequence_stack (void *);
#define gt_ggc_m_13libfunc_entry(X) do { \
  if (X != NULL) gt_ggc_mx_libfunc_entry (X);\
  } while (0)
extern void gt_ggc_mx_libfunc_entry (void *);
#define gt_ggc_m_12tree_vec_map(X) do { \
  if (X != NULL) gt_ggc_mx_tree_vec_map (X);\
  } while (0)
extern void gt_ggc_mx_tree_vec_map (void *);
#define gt_ggc_m_17tree_priority_map(X) do { \
  if (X != NULL) gt_ggc_mx_tree_priority_map (X);\
  } while (0)
extern void gt_ggc_mx_tree_priority_map (void *);
#define gt_ggc_m_12tree_int_map(X) do { \
  if (X != NULL) gt_ggc_mx_tree_int_map (X);\
  } while (0)
extern void gt_ggc_mx_tree_int_map (void *);
#define gt_ggc_m_13tree_decl_map(X) do { \
  if (X != NULL) gt_ggc_mx_tree_decl_map (X);\
  } while (0)
extern void gt_ggc_mx_tree_decl_map (void *);
#define gt_ggc_m_8tree_map(X) do { \
  if (X != NULL) gt_ggc_mx_tree_map (X);\
  } while (0)
extern void gt_ggc_mx_tree_map (void *);
#define gt_ggc_m_14lang_tree_node(X) do { \
  if (X != NULL) gt_ggc_mx_lang_tree_node (X);\
  } while (0)
extern void gt_ggc_mx_lang_tree_node (void *);
#define gt_ggc_m_24tree_statement_list_node(X) do { \
  if (X != NULL) gt_ggc_mx_tree_statement_list_node (X);\
  } while (0)
extern void gt_ggc_mx_tree_statement_list_node (void *);
#define gt_ggc_m_9var_ann_d(X) do { \
  if (X != NULL) gt_ggc_mx_var_ann_d (X);\
  } while (0)
extern void gt_ggc_mx_var_ann_d (void *);
#define gt_ggc_m_9lang_decl(X) do { \
  if (X != NULL) gt_ggc_mx_lang_decl (X);\
  } while (0)
extern void gt_ggc_mx_lang_decl (void *);
#define gt_ggc_m_9lang_type(X) do { \
  if (X != NULL) gt_ggc_mx_lang_type (X);\
  } while (0)
extern void gt_ggc_mx_lang_type (void *);
#define gt_ggc_m_10die_struct(X) do { \
  if (X != NULL) gt_ggc_mx_die_struct (X);\
  } while (0)
extern void gt_ggc_mx_die_struct (void *);
#define gt_ggc_m_12ptr_info_def(X) do { \
  if (X != NULL) gt_ggc_mx_ptr_info_def (X);\
  } while (0)
extern void gt_ggc_mx_ptr_info_def (void *);
#define gt_ggc_m_22VEC_constructor_elt_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_constructor_elt_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_constructor_elt_gc (void *);
#define gt_ggc_m_17VEC_alias_pair_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_alias_pair_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_alias_pair_gc (void *);
#define gt_ggc_m_8function(X) do { \
  if (X != NULL) gt_ggc_mx_function (X);\
  } while (0)
extern void gt_ggc_mx_function (void *);
#define gt_ggc_m_23constant_descriptor_rtx(X) do { \
  if (X != NULL) gt_ggc_mx_constant_descriptor_rtx (X);\
  } while (0)
extern void gt_ggc_mx_constant_descriptor_rtx (void *);
#define gt_ggc_m_11fixed_value(X) do { \
  if (X != NULL) gt_ggc_mx_fixed_value (X);\
  } while (0)
extern void gt_ggc_mx_fixed_value (void *);
#define gt_ggc_m_10real_value(X) do { \
  if (X != NULL) gt_ggc_mx_real_value (X);\
  } while (0)
extern void gt_ggc_mx_real_value (void *);
#define gt_ggc_m_12object_block(X) do { \
  if (X != NULL) gt_ggc_mx_object_block (X);\
  } while (0)
extern void gt_ggc_mx_object_block (void *);
#define gt_ggc_m_9reg_attrs(X) do { \
  if (X != NULL) gt_ggc_mx_reg_attrs (X);\
  } while (0)
extern void gt_ggc_mx_reg_attrs (void *);
#define gt_ggc_m_9mem_attrs(X) do { \
  if (X != NULL) gt_ggc_mx_mem_attrs (X);\
  } while (0)
extern void gt_ggc_mx_mem_attrs (void *);
#define gt_ggc_m_14bitmap_obstack(X) do { \
  if (X != NULL) gt_ggc_mx_bitmap_obstack (X);\
  } while (0)
extern void gt_ggc_mx_bitmap_obstack (void *);
#define gt_ggc_m_18bitmap_element_def(X) do { \
  if (X != NULL) gt_ggc_mx_bitmap_element_def (X);\
  } while (0)
extern void gt_ggc_mx_bitmap_element_def (void *);
#define gt_ggc_m_16machine_function(X) do { \
  if (X != NULL) gt_ggc_mx_machine_function (X);\
  } while (0)
extern void gt_ggc_mx_machine_function (void *);
#define gt_ggc_m_17stack_local_entry(X) do { \
  if (X != NULL) gt_ggc_mx_stack_local_entry (X);\
  } while (0)
extern void gt_ggc_mx_stack_local_entry (void *);
#define gt_ggc_m_10VEC_rtx_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_rtx_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_rtx_gc (void *);
#define gt_ggc_m_13VEC_gimple_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_gimple_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_gimple_gc (void *);
#define gt_ggc_m_11VEC_tree_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_tree_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_tree_gc (void *);
#define gt_ggc_m_12VEC_uchar_gc(X) do { \
  if (X != NULL) gt_ggc_mx_VEC_uchar_gc (X);\
  } while (0)
extern void gt_ggc_mx_VEC_uchar_gc (void *);
#define gt_ggc_m_15basic_block_def(X) do { \
  if (X != NULL) gt_ggc_mx_basic_block_def (X);\
  } while (0)
extern void gt_ggc_mx_basic_block_def (void *);
#define gt_ggc_m_8edge_def(X) do { \
  if (X != NULL) gt_ggc_mx_edge_def (X);\
  } while (0)
extern void gt_ggc_mx_edge_def (void *);
#define gt_ggc_m_12gimple_seq_d(X) do { \
  if (X != NULL) gt_ggc_mx_gimple_seq_d (X);\
  } while (0)
extern void gt_ggc_mx_gimple_seq_d (void *);
#define gt_ggc_m_7section(X) do { \
  if (X != NULL) gt_ggc_mx_section (X);\
  } while (0)
extern void gt_ggc_mx_section (void *);
#define gt_ggc_m_18gimple_statement_d(X) do { \
  if (X != NULL) gt_ggc_mx_gimple_statement_d (X);\
  } while (0)
extern void gt_ggc_mx_gimple_statement_d (void *);
#define gt_ggc_m_9rtvec_def(X) do { \
  if (X != NULL) gt_ggc_mx_rtvec_def (X);\
  } while (0)
extern void gt_ggc_mx_rtvec_def (void *);
#define gt_ggc_m_7rtx_def(X) do { \
  if (X != NULL) gt_ggc_mx_rtx_def (X);\
  } while (0)
extern void gt_ggc_mx_rtx_def (void *);
#define gt_ggc_m_15bitmap_head_def(X) do { \
  if (X != NULL) gt_ggc_mx_bitmap_head_def (X);\
  } while (0)
extern void gt_ggc_mx_bitmap_head_def (void *);
#define gt_ggc_m_9tree_node(X) do { \
  if (X != NULL) gt_ggc_mx_tree_node (X);\
  } while (0)
#define gt_ggc_mx_tree_node gt_ggc_mx_lang_tree_node
#define gt_ggc_m_6answer(X) do { \
  if (X != NULL) gt_ggc_mx_answer (X);\
  } while (0)
extern void gt_ggc_mx_answer (void *);
#define gt_ggc_m_9cpp_macro(X) do { \
  if (X != NULL) gt_ggc_mx_cpp_macro (X);\
  } while (0)
extern void gt_ggc_mx_cpp_macro (void *);
#define gt_ggc_m_9cpp_token(X) do { \
  if (X != NULL) gt_ggc_mx_cpp_token (X);\
  } while (0)
extern void gt_ggc_mx_cpp_token (void *);
#define gt_ggc_m_9line_maps(X) do { \
  if (X != NULL) gt_ggc_mx_line_maps (X);\
  } while (0)
extern void gt_ggc_mx_line_maps (void *);
extern void gt_ggc_m_P11tree2WeakVH4htab (void *);
extern void gt_ggc_m_P9tree2Type4htab (void *);
extern void gt_ggc_m_P8tree2int4htab (void *);
extern void gt_ggc_m_II17splay_tree_node_s (void *);
extern void gt_ggc_m_SP9tree_node17splay_tree_node_s (void *);
extern void gt_ggc_m_P9tree_nodeP9tree_node17splay_tree_node_s (void *);
extern void gt_ggc_m_P15interface_tuple4htab (void *);
extern void gt_ggc_m_P17string_descriptor4htab (void *);
extern void gt_ggc_m_P14type_assertion4htab (void *);
extern void gt_ggc_m_P18treetreehash_entry4htab (void *);
extern void gt_ggc_m_P17module_htab_entry4htab (void *);
extern void gt_ggc_m_P21pending_abstract_type4htab (void *);
extern void gt_ggc_m_P14constexpr_call4htab (void *);
extern void gt_ggc_m_P16constexpr_fundef4htab (void *);
extern void gt_ggc_m_P10spec_entry4htab (void *);
extern void gt_ggc_m_P16cxx_int_tree_map4htab (void *);
extern void gt_ggc_m_P17named_label_entry4htab (void *);
extern void gt_ggc_m_P17lto_in_decl_state4htab (void *);
extern void gt_ggc_m_P20lto_symtab_entry_def4htab (void *);
extern void gt_ggc_m_P8tree_map4htab (void *);
extern void gt_ggc_m_P9tree_nodeP9tree_node12splay_tree_s (void *);
extern void gt_ggc_m_P12varpool_node4htab (void *);
extern void gt_ggc_m_P13scev_info_str4htab (void *);
extern void gt_ggc_m_P12tree_int_map4htab (void *);
extern void gt_ggc_m_P23constant_descriptor_rtx4htab (void *);
extern void gt_ggc_m_P24constant_descriptor_tree4htab (void *);
extern void gt_ggc_m_P12object_block4htab (void *);
extern void gt_ggc_m_P7section4htab (void *);
extern void gt_ggc_m_P17tree_priority_map4htab (void *);
extern void gt_ggc_m_P12tree_vec_map4htab (void *);
extern void gt_ggc_m_P13tree_decl_map4htab (void *);
extern void gt_ggc_m_P9type_hash4htab (void *);
extern void gt_ggc_m_P23temp_slot_address_entry4htab (void *);
extern void gt_ggc_m_P15throw_stmt_node4htab (void *);
extern void gt_ggc_m_P9reg_attrs4htab (void *);
extern void gt_ggc_m_P9mem_attrs4htab (void *);
extern void gt_ggc_m_P7rtx_def4htab (void *);
extern void gt_ggc_m_P22cached_dw_loc_list_def4htab (void *);
extern void gt_ggc_m_P16var_loc_list_def4htab (void *);
extern void gt_ggc_m_P10die_struct4htab (void *);
extern void gt_ggc_m_P15dwarf_file_data4htab (void *);
extern void gt_ggc_m_P20indirect_string_node4htab (void *);
extern void gt_ggc_m_SP9tree_node12splay_tree_s (void *);
extern void gt_ggc_m_P11cgraph_node4htab (void *);
extern void gt_ggc_m_II12splay_tree_s (void *);
extern void gt_ggc_m_P11cgraph_edge4htab (void *);
extern void gt_ggc_m_P9loop_exit4htab (void *);
extern void gt_ggc_m_P24types_used_by_vars_entry4htab (void *);
extern void gt_ggc_m_P9tree_node4htab (void *);
extern void gt_ggc_m_P13libfunc_entry4htab (void *);

/* functions code */

void
gt_ggc_mx_tree2WeakVH (void *x_p)
{
  struct tree2WeakVH * const x = (struct tree2WeakVH *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).base.from);
    }
}

void
gt_ggc_mx_tree2Type (void *x_p)
{
  struct tree2Type * const x = (struct tree2Type *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).base.from);
    }
}

void
gt_ggc_mx_tree2int (void *x_p)
{
  struct tree2int * const x = (struct tree2int *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).base.from);
    }
}

void
gt_ggc_m_P11tree2WeakVH4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_11tree2WeakVH ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

void
gt_ggc_m_P9tree2Type4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_9tree2Type ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

void
gt_ggc_m_P8tree2int4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_8tree2int ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

/* GC roots.  */

EXPORTED_CONST struct ggc_cache_tab gt_ggc_rc__gt_cache_h[] = {
  {
    &WeakVHCache,
    1,
    sizeof (WeakVHCache),
    &gt_ggc_mx_tree2WeakVH,
    NULL,
    &tree2WeakVH_marked_p
  },
  {
    &TypeCache,
    1,
    sizeof (TypeCache),
    &gt_ggc_mx_tree2Type,
    NULL,
    &tree2Type_marked_p
  },
  {
    &intCache,
    1,
    sizeof (intCache),
    &gt_ggc_mx_tree2int,
    NULL,
    &tree2int_marked_p
  },
  LAST_GGC_CACHE_TAB
};


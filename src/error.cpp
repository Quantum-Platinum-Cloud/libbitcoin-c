/**
 * Copyright (c) 2011-2016 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/bitcoin/c/error.h>

#include <bitcoin/bitcoin/c/internal/error.hpp>
#include <bitcoin/bitcoin/c/internal/utility/string.hpp>

extern "C" {

bc_error_code_t* bc_create_error_code(bc_error_t error)
{
    return new bc_error_code_t{ new std::error_code(
        bc_error_code_from_ctype(error)) };
}
bc_error_code_t* bc_create_error_code_default()
{
    return new bc_error_code_t{ new std::error_code };
}
void bc_destroy_error_code(bc_error_code_t* self)
{
    delete self->obj;
    delete self;
}
bc_string_t* bc_error_code__message(const bc_error_code_t* self)
{
    return bc_create_string_StdString(self->obj->message());
}
bool bc_error_code__is_valid(const bc_error_code_t* self)
{
    return static_cast<bool>(*self->obj);
}
bool bc_error_code__equals(const bc_error_code_t* self, bc_error_t ec)
{
    return *self->obj == bc_error_code_from_ctype(ec);
}

} // extern C

// C++ convenience functions
bc_error_t bc_error_code_to_ctype(libbitcoin::error::error_code_t value)
{
    switch (value)
    {
        case libbitcoin::error::success:
            return bc_error__success;
        case libbitcoin::error::deprecated:
            return bc_error__deprecated;
        case libbitcoin::error::unknown:
            return bc_error__unknown;
        case libbitcoin::error::not_found:
            return bc_error__not_found;
        case libbitcoin::error::file_system:
            return bc_error__file_system;
        case libbitcoin::error::non_standard:
            return bc_error__non_standard;
        case libbitcoin::error::not_implemented:
            return bc_error__not_implemented;
        case libbitcoin::error::service_stopped:
            return bc_error__service_stopped;
        case libbitcoin::error::operation_failed:
            return bc_error__operation_failed;
        case libbitcoin::error::resolve_failed:
            return bc_error__resolve_failed;
        case libbitcoin::error::network_unreachable:
            return bc_error__network_unreachable;
        case libbitcoin::error::address_in_use:
            return bc_error__address_in_use;
        case libbitcoin::error::listen_failed:
            return bc_error__listen_failed;
        case libbitcoin::error::accept_failed:
            return bc_error__accept_failed;
        case libbitcoin::error::bad_stream:
            return bc_error__bad_stream;
        case libbitcoin::error::channel_timeout:
            return bc_error__channel_timeout;
        case libbitcoin::error::address_blocked:
            return bc_error__address_blocked;
        case libbitcoin::error::channel_stopped:
            return bc_error__channel_stopped;
        case libbitcoin::error::store_block_duplicate:
            return bc_error__store_block_duplicate;
        case libbitcoin::error::store_block_invalid_height:
            return bc_error__store_block_invalid_height;
        case libbitcoin::error::store_block_missing_parent:
            return bc_error__store_block_missing_parent;
        case libbitcoin::error::duplicate_block:
            return bc_error__duplicate_block;
        case libbitcoin::error::orphan_block:
            return bc_error__orphan_block;
        case libbitcoin::error::invalid_previous_block:
            return bc_error__invalid_previous_block;
        case libbitcoin::error::insufficient_work:
            return bc_error__insufficient_work;
        case libbitcoin::error::orphan_transaction:
            return bc_error__orphan_transaction;
        case libbitcoin::error::invalid_proof_of_work:
            return bc_error__invalid_proof_of_work;
        case libbitcoin::error::futuristic_timestamp:
            return bc_error__futuristic_timestamp;
        case libbitcoin::error::checkpoints_failed:
            return bc_error__checkpoints_failed;
        case libbitcoin::error::old_version_block:
            return bc_error__old_version_block;
        case libbitcoin::error::incorrect_proof_of_work:
            return bc_error__incorrect_proof_of_work;
        case libbitcoin::error::timestamp_too_early:
            return bc_error__timestamp_too_early;
        case libbitcoin::error::block_size_limit:
            return bc_error__block_size_limit;
        case libbitcoin::error::empty_block:
            return bc_error__empty_block;
        case libbitcoin::error::first_not_coinbase:
            return bc_error__first_not_coinbase;
        case libbitcoin::error::extra_coinbases:
            return bc_error__extra_coinbases;
        case libbitcoin::error::internal_duplicate:
            return bc_error__internal_duplicate;
        case libbitcoin::error::internal_double_spend:
            return bc_error__internal_double_spend;
        case libbitcoin::error::merkle_mismatch:
            return bc_error__merkle_mismatch;
        case libbitcoin::error::block_legacy_sigop_limit:
            return bc_error__block_legacy_sigop_limit;
        case libbitcoin::error::non_final_transaction:
            return bc_error__non_final_transaction;
        case libbitcoin::error::coinbase_height_mismatch:
            return bc_error__coinbase_height_mismatch;
        case libbitcoin::error::coinbase_value_limit:
            return bc_error__coinbase_value_limit;
        case libbitcoin::error::block_embedded_sigop_limit:
            return bc_error__block_embedded_sigop_limit;
        case libbitcoin::error::empty_transaction:
            return bc_error__empty_transaction;
        case libbitcoin::error::previous_output_null:
            return bc_error__previous_output_null;
        case libbitcoin::error::spend_overflow:
            return bc_error__spend_overflow;
        case libbitcoin::error::invalid_coinbase_script_size:
            return bc_error__invalid_coinbase_script_size;
        case libbitcoin::error::coinbase_transaction:
            return bc_error__coinbase_transaction;
        case libbitcoin::error::transction_size_limit:
            return bc_error__transction_size_limit;
        case libbitcoin::error::transaction_legacy_sigop_limit:
            return bc_error__transaction_legacy_sigop_limit;
        case libbitcoin::error::unspent_duplicate:
            return bc_error__unspent_duplicate;
        case libbitcoin::error::missing_previous_output:
            return bc_error__missing_previous_output;
        case libbitcoin::error::double_spend:
            return bc_error__double_spend;
        case libbitcoin::error::coinbase_maturity:
            return bc_error__coinbase_maturity;
        case libbitcoin::error::spend_exceeds_value:
            return bc_error__spend_exceeds_value;
        case libbitcoin::error::transaction_embedded_sigop_limit:
            return bc_error__transaction_embedded_sigop_limit;
        case libbitcoin::error::invalid_script:
            return bc_error__invalid_script;
        case libbitcoin::error::invalid_script_size:
            return bc_error__invalid_script_size;
        case libbitcoin::error::invalid_push_data_size:
            return bc_error__invalid_push_data_size;
        case libbitcoin::error::invalid_operation_count:
            return bc_error__invalid_operation_count;
        case libbitcoin::error::invalid_stack_size:
            return bc_error__invalid_stack_size;
        case libbitcoin::error::invalid_stack_scope:
            return bc_error__invalid_stack_scope;
        case libbitcoin::error::invalid_script_embed:
            return bc_error__invalid_script_embed;
        case libbitcoin::error::invalid_signature_encoding:
            return bc_error__invalid_signature_encoding;
        case libbitcoin::error::invalid_signature_lax_encoding:
            return bc_error__invalid_signature_lax_encoding;
        case libbitcoin::error::incorrect_signature:
            return bc_error__incorrect_signature;
        case libbitcoin::error::stack_false:
            return bc_error__stack_false;
        case libbitcoin::error::op_disabled:
            return bc_error__op_disabled;
        case libbitcoin::error::op_reserved:
            return bc_error__op_reserved;
        case libbitcoin::error::op_push_size:
            return bc_error__op_push_size;
        case libbitcoin::error::op_push_data:
            return bc_error__op_push_data;
        case libbitcoin::error::op_if:
            return bc_error__op_if;
        case libbitcoin::error::op_notif:
            return bc_error__op_notif;
        case libbitcoin::error::op_else:
            return bc_error__op_else;
        case libbitcoin::error::op_endif:
            return bc_error__op_endif;
        case libbitcoin::error::op_verify1:
            return bc_error__op_verify1;
        case libbitcoin::error::op_verify2:
            return bc_error__op_verify2;
        case libbitcoin::error::op_return:
            return bc_error__op_return;
        case libbitcoin::error::op_to_alt_stack:
            return bc_error__op_to_alt_stack;
        case libbitcoin::error::op_from_alt_stack:
            return bc_error__op_from_alt_stack;
        case libbitcoin::error::op_drop2:
            return bc_error__op_drop2;
        case libbitcoin::error::op_dup2:
            return bc_error__op_dup2;
        case libbitcoin::error::op_dup3:
            return bc_error__op_dup3;
        case libbitcoin::error::op_over2:
            return bc_error__op_over2;
        case libbitcoin::error::op_rot2:
            return bc_error__op_rot2;
        case libbitcoin::error::op_swap2:
            return bc_error__op_swap2;
        case libbitcoin::error::op_if_dup:
            return bc_error__op_if_dup;
        case libbitcoin::error::op_drop:
            return bc_error__op_drop;
        case libbitcoin::error::op_dup:
            return bc_error__op_dup;
        case libbitcoin::error::op_nip:
            return bc_error__op_nip;
        case libbitcoin::error::op_over:
            return bc_error__op_over;
        case libbitcoin::error::op_pick:
            return bc_error__op_pick;
        case libbitcoin::error::op_roll:
            return bc_error__op_roll;
        case libbitcoin::error::op_rot:
            return bc_error__op_rot;
        case libbitcoin::error::op_swap:
            return bc_error__op_swap;
        case libbitcoin::error::op_tuck:
            return bc_error__op_tuck;
        case libbitcoin::error::op_size:
            return bc_error__op_size;
        case libbitcoin::error::op_equal:
            return bc_error__op_equal;
        case libbitcoin::error::op_equal_verify1:
            return bc_error__op_equal_verify1;
        case libbitcoin::error::op_equal_verify2:
            return bc_error__op_equal_verify2;
        case libbitcoin::error::op_add1:
            return bc_error__op_add1;
        case libbitcoin::error::op_sub1:
            return bc_error__op_sub1;
        case libbitcoin::error::op_negate:
            return bc_error__op_negate;
        case libbitcoin::error::op_abs:
            return bc_error__op_abs;
        case libbitcoin::error::op_not:
            return bc_error__op_not;
        case libbitcoin::error::op_nonzero:
            return bc_error__op_nonzero;
        case libbitcoin::error::op_add:
            return bc_error__op_add;
        case libbitcoin::error::op_sub:
            return bc_error__op_sub;
        case libbitcoin::error::op_bool_and:
            return bc_error__op_bool_and;
        case libbitcoin::error::op_bool_or:
            return bc_error__op_bool_or;
        case libbitcoin::error::op_num_equal:
            return bc_error__op_num_equal;
        case libbitcoin::error::op_num_equal_verify1:
            return bc_error__op_num_equal_verify1;
        case libbitcoin::error::op_num_equal_verify2:
            return bc_error__op_num_equal_verify2;
        case libbitcoin::error::op_num_not_equal:
            return bc_error__op_num_not_equal;
        case libbitcoin::error::op_less_than:
            return bc_error__op_less_than;
        case libbitcoin::error::op_greater_than:
            return bc_error__op_greater_than;
        case libbitcoin::error::op_less_than_or_equal:
            return bc_error__op_less_than_or_equal;
        case libbitcoin::error::op_greater_than_or_equal:
            return bc_error__op_greater_than_or_equal;
        case libbitcoin::error::op_min:
            return bc_error__op_min;
        case libbitcoin::error::op_max:
            return bc_error__op_max;
        case libbitcoin::error::op_within:
            return bc_error__op_within;
        case libbitcoin::error::op_ripemd160:
            return bc_error__op_ripemd160;
        case libbitcoin::error::op_sha1:
            return bc_error__op_sha1;
        case libbitcoin::error::op_sha256:
            return bc_error__op_sha256;
        case libbitcoin::error::op_hash160:
            return bc_error__op_hash160;
        case libbitcoin::error::op_hash256:
            return bc_error__op_hash256;
        case libbitcoin::error::op_code_seperator:
            return bc_error__op_code_seperator;
        case libbitcoin::error::op_check_sig_verify1:
            return bc_error__op_check_sig_verify1;
        case libbitcoin::error::op_check_sig:
            return bc_error__op_check_sig;
        case libbitcoin::error::op_check_multisig_verify1:
            return bc_error__op_check_multisig_verify1;
        case libbitcoin::error::op_check_multisig_verify2:
            return bc_error__op_check_multisig_verify2;
        case libbitcoin::error::op_check_multisig_verify3:
            return bc_error__op_check_multisig_verify3;
        case libbitcoin::error::op_check_multisig_verify4:
            return bc_error__op_check_multisig_verify4;
        case libbitcoin::error::op_check_multisig_verify5:
            return bc_error__op_check_multisig_verify5;
        case libbitcoin::error::op_check_multisig_verify6:
            return bc_error__op_check_multisig_verify6;
        case libbitcoin::error::op_check_multisig_verify7:
            return bc_error__op_check_multisig_verify7;
        case libbitcoin::error::op_check_multisig:
            return bc_error__op_check_multisig;
        case libbitcoin::error::op_check_locktime_verify1:
            return bc_error__op_check_locktime_verify1;
        case libbitcoin::error::op_check_locktime_verify2:
            return bc_error__op_check_locktime_verify2;
        case libbitcoin::error::op_check_locktime_verify3:
            return bc_error__op_check_locktime_verify3;
        case libbitcoin::error::op_check_locktime_verify4:
            return bc_error__op_check_locktime_verify4;
        case libbitcoin::error::op_check_locktime_verify5:
            return bc_error__op_check_locktime_verify5;
        case libbitcoin::error::op_check_locktime_verify6:
            return bc_error__op_check_locktime_verify6;
    }
}
libbitcoin::error::error_code_t bc_error_code_from_ctype(bc_error_t value)
{
    switch (value)
    {
        case bc_error__success:
            return libbitcoin::error::success;
        case bc_error__deprecated:
            return libbitcoin::error::deprecated;
        case bc_error__unknown:
            return libbitcoin::error::unknown;
        case bc_error__not_found:
            return libbitcoin::error::not_found;
        case bc_error__file_system:
            return libbitcoin::error::file_system;
        case bc_error__non_standard:
            return libbitcoin::error::non_standard;
        case bc_error__not_implemented:
            return libbitcoin::error::not_implemented;
        case bc_error__service_stopped:
            return libbitcoin::error::service_stopped;
        case bc_error__operation_failed:
            return libbitcoin::error::operation_failed;
        case bc_error__resolve_failed:
            return libbitcoin::error::resolve_failed;
        case bc_error__network_unreachable:
            return libbitcoin::error::network_unreachable;
        case bc_error__address_in_use:
            return libbitcoin::error::address_in_use;
        case bc_error__listen_failed:
            return libbitcoin::error::listen_failed;
        case bc_error__accept_failed:
            return libbitcoin::error::accept_failed;
        case bc_error__bad_stream:
            return libbitcoin::error::bad_stream;
        case bc_error__channel_timeout:
            return libbitcoin::error::channel_timeout;
        case bc_error__address_blocked:
            return libbitcoin::error::address_blocked;
        case bc_error__channel_stopped:
            return libbitcoin::error::channel_stopped;
        case bc_error__store_block_duplicate:
            return libbitcoin::error::store_block_duplicate;
        case bc_error__store_block_invalid_height:
            return libbitcoin::error::store_block_invalid_height;
        case bc_error__store_block_missing_parent:
            return libbitcoin::error::store_block_missing_parent;
        case bc_error__duplicate_block:
            return libbitcoin::error::duplicate_block;
        case bc_error__orphan_block:
            return libbitcoin::error::orphan_block;
        case bc_error__invalid_previous_block:
            return libbitcoin::error::invalid_previous_block;
        case bc_error__insufficient_work:
            return libbitcoin::error::insufficient_work;
        case bc_error__orphan_transaction:
            return libbitcoin::error::orphan_transaction;
        case bc_error__invalid_proof_of_work:
            return libbitcoin::error::invalid_proof_of_work;
        case bc_error__futuristic_timestamp:
            return libbitcoin::error::futuristic_timestamp;
        case bc_error__checkpoints_failed:
            return libbitcoin::error::checkpoints_failed;
        case bc_error__old_version_block:
            return libbitcoin::error::old_version_block;
        case bc_error__incorrect_proof_of_work:
            return libbitcoin::error::incorrect_proof_of_work;
        case bc_error__timestamp_too_early:
            return libbitcoin::error::timestamp_too_early;
        case bc_error__block_size_limit:
            return libbitcoin::error::block_size_limit;
        case bc_error__empty_block:
            return libbitcoin::error::empty_block;
        case bc_error__first_not_coinbase:
            return libbitcoin::error::first_not_coinbase;
        case bc_error__extra_coinbases:
            return libbitcoin::error::extra_coinbases;
        case bc_error__internal_duplicate:
            return libbitcoin::error::internal_duplicate;
        case bc_error__internal_double_spend:
            return libbitcoin::error::internal_double_spend;
        case bc_error__merkle_mismatch:
            return libbitcoin::error::merkle_mismatch;
        case bc_error__block_legacy_sigop_limit:
            return libbitcoin::error::block_legacy_sigop_limit;
        case bc_error__non_final_transaction:
            return libbitcoin::error::non_final_transaction;
        case bc_error__coinbase_height_mismatch:
            return libbitcoin::error::coinbase_height_mismatch;
        case bc_error__coinbase_value_limit:
            return libbitcoin::error::coinbase_value_limit;
        case bc_error__block_embedded_sigop_limit:
            return libbitcoin::error::block_embedded_sigop_limit;
        case bc_error__empty_transaction:
            return libbitcoin::error::empty_transaction;
        case bc_error__previous_output_null:
            return libbitcoin::error::previous_output_null;
        case bc_error__spend_overflow:
            return libbitcoin::error::spend_overflow;
        case bc_error__invalid_coinbase_script_size:
            return libbitcoin::error::invalid_coinbase_script_size;
        case bc_error__coinbase_transaction:
            return libbitcoin::error::coinbase_transaction;
        case bc_error__transction_size_limit:
            return libbitcoin::error::transction_size_limit;
        case bc_error__transaction_legacy_sigop_limit:
            return libbitcoin::error::transaction_legacy_sigop_limit;
        case bc_error__unspent_duplicate:
            return libbitcoin::error::unspent_duplicate;
        case bc_error__missing_previous_output:
            return libbitcoin::error::missing_previous_output;
        case bc_error__double_spend:
            return libbitcoin::error::double_spend;
        case bc_error__coinbase_maturity:
            return libbitcoin::error::coinbase_maturity;
        case bc_error__spend_exceeds_value:
            return libbitcoin::error::spend_exceeds_value;
        case bc_error__transaction_embedded_sigop_limit:
            return libbitcoin::error::transaction_embedded_sigop_limit;
        case bc_error__invalid_script:
            return libbitcoin::error::invalid_script;
        case bc_error__invalid_script_size:
            return libbitcoin::error::invalid_script_size;
        case bc_error__invalid_push_data_size:
            return libbitcoin::error::invalid_push_data_size;
        case bc_error__invalid_operation_count:
            return libbitcoin::error::invalid_operation_count;
        case bc_error__invalid_stack_size:
            return libbitcoin::error::invalid_stack_size;
        case bc_error__invalid_stack_scope:
            return libbitcoin::error::invalid_stack_scope;
        case bc_error__invalid_script_embed:
            return libbitcoin::error::invalid_script_embed;
        case bc_error__invalid_signature_encoding:
            return libbitcoin::error::invalid_signature_encoding;
        case bc_error__invalid_signature_lax_encoding:
            return libbitcoin::error::invalid_signature_lax_encoding;
        case bc_error__incorrect_signature:
            return libbitcoin::error::incorrect_signature;
        case bc_error__stack_false:
            return libbitcoin::error::stack_false;
        case bc_error__op_disabled:
            return libbitcoin::error::op_disabled;
        case bc_error__op_reserved:
            return libbitcoin::error::op_reserved;
        case bc_error__op_push_size:
            return libbitcoin::error::op_push_size;
        case bc_error__op_push_data:
            return libbitcoin::error::op_push_data;
        case bc_error__op_if:
            return libbitcoin::error::op_if;
        case bc_error__op_notif:
            return libbitcoin::error::op_notif;
        case bc_error__op_else:
            return libbitcoin::error::op_else;
        case bc_error__op_endif:
            return libbitcoin::error::op_endif;
        case bc_error__op_verify1:
            return libbitcoin::error::op_verify1;
        case bc_error__op_verify2:
            return libbitcoin::error::op_verify2;
        case bc_error__op_return:
            return libbitcoin::error::op_return;
        case bc_error__op_to_alt_stack:
            return libbitcoin::error::op_to_alt_stack;
        case bc_error__op_from_alt_stack:
            return libbitcoin::error::op_from_alt_stack;
        case bc_error__op_drop2:
            return libbitcoin::error::op_drop2;
        case bc_error__op_dup2:
            return libbitcoin::error::op_dup2;
        case bc_error__op_dup3:
            return libbitcoin::error::op_dup3;
        case bc_error__op_over2:
            return libbitcoin::error::op_over2;
        case bc_error__op_rot2:
            return libbitcoin::error::op_rot2;
        case bc_error__op_swap2:
            return libbitcoin::error::op_swap2;
        case bc_error__op_if_dup:
            return libbitcoin::error::op_if_dup;
        case bc_error__op_drop:
            return libbitcoin::error::op_drop;
        case bc_error__op_dup:
            return libbitcoin::error::op_dup;
        case bc_error__op_nip:
            return libbitcoin::error::op_nip;
        case bc_error__op_over:
            return libbitcoin::error::op_over;
        case bc_error__op_pick:
            return libbitcoin::error::op_pick;
        case bc_error__op_roll:
            return libbitcoin::error::op_roll;
        case bc_error__op_rot:
            return libbitcoin::error::op_rot;
        case bc_error__op_swap:
            return libbitcoin::error::op_swap;
        case bc_error__op_tuck:
            return libbitcoin::error::op_tuck;
        case bc_error__op_size:
            return libbitcoin::error::op_size;
        case bc_error__op_equal:
            return libbitcoin::error::op_equal;
        case bc_error__op_equal_verify1:
            return libbitcoin::error::op_equal_verify1;
        case bc_error__op_equal_verify2:
            return libbitcoin::error::op_equal_verify2;
        case bc_error__op_add1:
            return libbitcoin::error::op_add1;
        case bc_error__op_sub1:
            return libbitcoin::error::op_sub1;
        case bc_error__op_negate:
            return libbitcoin::error::op_negate;
        case bc_error__op_abs:
            return libbitcoin::error::op_abs;
        case bc_error__op_not:
            return libbitcoin::error::op_not;
        case bc_error__op_nonzero:
            return libbitcoin::error::op_nonzero;
        case bc_error__op_add:
            return libbitcoin::error::op_add;
        case bc_error__op_sub:
            return libbitcoin::error::op_sub;
        case bc_error__op_bool_and:
            return libbitcoin::error::op_bool_and;
        case bc_error__op_bool_or:
            return libbitcoin::error::op_bool_or;
        case bc_error__op_num_equal:
            return libbitcoin::error::op_num_equal;
        case bc_error__op_num_equal_verify1:
            return libbitcoin::error::op_num_equal_verify1;
        case bc_error__op_num_equal_verify2:
            return libbitcoin::error::op_num_equal_verify2;
        case bc_error__op_num_not_equal:
            return libbitcoin::error::op_num_not_equal;
        case bc_error__op_less_than:
            return libbitcoin::error::op_less_than;
        case bc_error__op_greater_than:
            return libbitcoin::error::op_greater_than;
        case bc_error__op_less_than_or_equal:
            return libbitcoin::error::op_less_than_or_equal;
        case bc_error__op_greater_than_or_equal:
            return libbitcoin::error::op_greater_than_or_equal;
        case bc_error__op_min:
            return libbitcoin::error::op_min;
        case bc_error__op_max:
            return libbitcoin::error::op_max;
        case bc_error__op_within:
            return libbitcoin::error::op_within;
        case bc_error__op_ripemd160:
            return libbitcoin::error::op_ripemd160;
        case bc_error__op_sha1:
            return libbitcoin::error::op_sha1;
        case bc_error__op_sha256:
            return libbitcoin::error::op_sha256;
        case bc_error__op_hash160:
            return libbitcoin::error::op_hash160;
        case bc_error__op_hash256:
            return libbitcoin::error::op_hash256;
        case bc_error__op_code_seperator:
            return libbitcoin::error::op_code_seperator;
        case bc_error__op_check_sig_verify1:
            return libbitcoin::error::op_check_sig_verify1;
        case bc_error__op_check_sig:
            return libbitcoin::error::op_check_sig;
        case bc_error__op_check_multisig_verify1:
            return libbitcoin::error::op_check_multisig_verify1;
        case bc_error__op_check_multisig_verify2:
            return libbitcoin::error::op_check_multisig_verify2;
        case bc_error__op_check_multisig_verify3:
            return libbitcoin::error::op_check_multisig_verify3;
        case bc_error__op_check_multisig_verify4:
            return libbitcoin::error::op_check_multisig_verify4;
        case bc_error__op_check_multisig_verify5:
            return libbitcoin::error::op_check_multisig_verify5;
        case bc_error__op_check_multisig_verify6:
            return libbitcoin::error::op_check_multisig_verify6;
        case bc_error__op_check_multisig_verify7:
            return libbitcoin::error::op_check_multisig_verify7;
        case bc_error__op_check_multisig:
            return libbitcoin::error::op_check_multisig;
        case bc_error__op_check_locktime_verify1:
            return libbitcoin::error::op_check_locktime_verify1;
        case bc_error__op_check_locktime_verify2:
            return libbitcoin::error::op_check_locktime_verify2;
        case bc_error__op_check_locktime_verify3:
            return libbitcoin::error::op_check_locktime_verify3;
        case bc_error__op_check_locktime_verify4:
            return libbitcoin::error::op_check_locktime_verify4;
        case bc_error__op_check_locktime_verify5:
            return libbitcoin::error::op_check_locktime_verify5;
        case bc_error__op_check_locktime_verify6:
            return libbitcoin::error::op_check_locktime_verify6;
    }
}


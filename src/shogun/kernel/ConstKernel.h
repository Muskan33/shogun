/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Soeren Sonnenburg, Yuyu Zhang
 */

#ifndef _CONSTKERNEL_H___
#define _CONSTKERNEL_H___

#include <shogun/lib/config.h>

#include <shogun/mathematics/Math.h>
#include <shogun/lib/common.h>
#include <shogun/kernel/Kernel.h>
#include <shogun/features/Features.h>

namespace shogun
{
/** @brief The Constant Kernel returns a constant for all elements.
 *
 * A ``kernel'' that simply returns a single constant, i.e.
 * \f$k({\bf x}, {\bf x'})= c\f$
 *
 */
class ConstKernel: public Kernel
{
	public:
		
		ConstKernel();

		/** constructor
		 *
		 * @param c constant c
		 */
		ConstKernel(float64_t c);

		/** constructor
		 *
		 * @param l features of left-hand side
		 * @param r features of right-hand side
		 * @param c constant c
		 */
		ConstKernel(std::shared_ptr<Features> l, std::shared_ptr<Features >r, float64_t c);

		virtual ~ConstKernel();

		virtual bool init(std::shared_ptr<Features> l, std::shared_ptr<Features> r);

		virtual EKernelType get_kernel_type() { return K_CONST; }

		virtual EFeatureType get_feature_type() { return F_ANY; }

		virtual EFeatureClass get_feature_class() { return C_ANY; }

		virtual const char* get_name() const { return "ConstKernel"; }

	protected:
		virtual float64_t compute(int32_t row, int32_t col) { return m_const_val; }

	protected:
		float64_t m_const_val = 1.0;
};
}
#endif /* _CONSTKERNEL_H__ */

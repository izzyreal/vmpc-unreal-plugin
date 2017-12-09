#pragma once
#include <controls/sampler/AbstractSamplerControls.hpp>

namespace mpc {
	namespace controls {
		namespace sampler {
			namespace window {

				class KeepOrRetryControls
					: public mpc::controls::sampler::AbstractSamplerControls
				{

				public:
					typedef mpc::controls::sampler::AbstractSamplerControls super;
					void function(int i) override;
					void turnWheel(int i) override;

					KeepOrRetryControls(mpc::Mpc* mpc);

				};

			}
		}
	}
}

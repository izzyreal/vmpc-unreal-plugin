#pragma once
#include <control/Control.hpp>
//#include <control/CompoundControlPersistence.hpp>

namespace ctoot {
	namespace control {
		class CompoundControl
			: public Control
		{

		private:
			//static CompoundControlPersistence* persistence_;

		public:
			static const int USE_PARENT_PROVIDER_ID{ 0 };

			static int deriveInstanceIndex(std::string name);

		protected:
			std::vector<std::shared_ptr<Control>> controls{};

		public:
			int instanceIndex = 0;

		public:
			int providerId = USE_PARENT_PROVIDER_ID;

		public:
			std::vector<std::string> getControlNamesRecursive(int generation);

		public:
			virtual void checkInstanceIndex(int index);
			virtual int getMaxInstance();
			virtual void add(std::shared_ptr<Control> control);
			virtual void remove(std::weak_ptr<Control> control);

		public:
			std::vector<std::weak_ptr<Control>> getMemberControls();
			virtual std::vector<std::weak_ptr<Control>> getControls();
			virtual std::string toString();
			virtual bool isAlwaysVertical();
			virtual bool isAlwaysHorizontal();
			virtual bool isNeverBordered();
			virtual float getAlignmentY();
			virtual std::string* getAlternate();
			virtual int getInstanceIndex();
			virtual std::weak_ptr<Control> findByTypeIdName(std::string typeIdName);
			virtual std::weak_ptr<Control> find(std::string name);
			virtual std::weak_ptr<CompoundControl> find(int providerId, int moduleId, int instanceIndex);
			virtual std::weak_ptr<Control> deepFind(int controlId);
			//static CompoundControlPersistence* getPersistence();
			//static void setPersistence(CompoundControlPersistence* p);
			virtual bool canBeMoved();
			virtual bool canBeMovedBefore();
			virtual bool canBeInsertedBefore();
			virtual bool canBeDeleted();
			virtual bool canBeMinimized();
			virtual bool hasPresets();
			virtual bool hasCustomUI();
			virtual bool canLearn();
			virtual bool getLearn();
			virtual void setLearn(bool learn);
			virtual std::string getPersistenceDomain();
			virtual bool isPluginParent();
			virtual int getProviderId();
			virtual void setProviderId(int id);
			virtual void setInstanceIndex(int idx);

		public:
			virtual void disambiguate(std::weak_ptr<CompoundControl> c);

		public:
			virtual void close();

		private:

		public:
			virtual void setEnabled(bool enable) override;

		public:
			CompoundControl(int id, int instanceIndex, std::string name);
			CompoundControl(int id, std::string name);
			virtual ~CompoundControl();

		private:
			//static CompoundControlPersistence*& persistence();
			friend class ControlColumn;
			friend class ControlRow;
			friend class BypassControl;
		};

	}
}

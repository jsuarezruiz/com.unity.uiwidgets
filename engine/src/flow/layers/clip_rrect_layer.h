#include "flow/layers/container_layer.h"

namespace uiwidgets {

class ClipRRectLayer : public ContainerLayer {
 public:
  ClipRRectLayer(const SkRRect& clip_rrect, Clip clip_behavior);

  void Preroll(PrerollContext* context, const SkMatrix& matrix) override;

  void Paint(PaintContext& context) const override;

  bool UsesSaveLayer() const {
    return clip_behavior_ == Clip::antiAliasWithSaveLayer;
  }

 private:
  SkRRect clip_rrect_;
  Clip clip_behavior_;
  bool children_inside_clip_ = false;

  FML_DISALLOW_COPY_AND_ASSIGN(ClipRRectLayer);
};

}  // namespace uiwidgets

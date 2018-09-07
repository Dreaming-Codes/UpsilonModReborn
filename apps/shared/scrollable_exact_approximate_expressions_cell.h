#ifndef SHARED_SCROLLABLE_EXACT_APPROXIMATE_EXPRESSIONS_CELL_H
#define SHARED_SCROLLABLE_EXACT_APPROXIMATE_EXPRESSIONS_CELL_H

#include <escher.h>
#include "scrollable_exact_approximate_expressions_view.h"

namespace Shared {

class ScrollableExactApproximateExpressionsCell : public ::EvenOddCell, public Responder {
public:
  ScrollableExactApproximateExpressionsCell(Responder * parentResponder = nullptr);
  void setLayouts(Poincare::LayoutReference approximateLayout, Poincare::LayoutReference exactLayout) {
    return m_view.setLayouts(approximateLayout, exactLayout);
  }
  void setEqualMessage(I18n::Message equalSignMessage) {
    return m_view.setEqualMessage(equalSignMessage);
  }
  void setHighlighted(bool highlight) override;
  void setEven(bool even) override;
  void reloadCell() override;
  void reloadScroll();
  Responder * responder() override {
    return this;
  }
  Poincare::LayoutRef layoutRef() const override { return m_view.layoutRef(); }
  void didBecomeFirstResponder() override;
  constexpr static KDCoordinate k_margin = 5;
private:
  int numberOfSubviews() const override;
  View * subviewAtIndex(int index) override;
  void layoutSubviews() override;
  ScrollableExactApproximateExpressionsView m_view;
};

}

#endif

#include "MediaBuilder.hpp"

#include "adaptors/IWebViewAdaptor.hpp"
#include "media/WebView.hpp"

class WebViewBuilder : public BaseMediaBuilder<WebViewBuilder>
{
public:
    std::unique_ptr<WebView> build();

    WebViewBuilder& path(const boost::optional<std::string>& path) override;
    WebViewBuilder& duration(int duration) override;

    WebViewBuilder& width(int width);
    WebViewBuilder& height(int height);
    WebViewBuilder& transparent(const boost::optional<bool>& transparent);

protected:
    virtual std::unique_ptr<IWebViewAdaptor> createAdaptor();

private:
    std::unique_ptr<WebView> createWebView();
    boost::optional<int> parseDuration(const FilePath& path);

private:
    int m_width;
    int m_height;
    bool m_transparent;

};

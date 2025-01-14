#include "Includinglibaries.hpp"


// Function that plotts three sinus 
    auto addPlots
      = [firstRun
         = std::set<std::string>{}](auto const& name, auto const& plots, auto axesSetup) mutable {
            auto const plotRegion = ImGui::GetContentRegionAvail();
            if(ImPlot::BeginPlot(name, plotRegion)) {
                double x_min = std::numeric_limits<double>::max();
                double x_max = std::numeric_limits<double>::min();

                for(auto const& plot : plots) {
                    if(!plot.x.empty()) {
                        x_min = std::min(x_min, plot.x.front());
                        x_max = std::max(x_max, plot.x.back());
                    }
                }

                axesSetup(x_min, x_max);
                auto const limits = [&]() {
                    if(!firstRun.contains(name)) {
                        firstRun.insert(name);
                        return ImPlotRect(x_min, x_max, 0, 0);
                    }
                    return ImPlot::GetPlotLimits();
                }();

                auto addPlot = [&](auto const& plot_name, auto const& x, auto const& y) {
                    auto const start = [&]() {
                        auto p = std::lower_bound(x.begin(), x.end(), limits.X.Min);
                        if(p != x.begin()) {
                            return p - 1;
                        }
                        return p;
                    }();

                    auto const end = [&]() {
                        auto p = std::upper_bound(start, x.end(), limits.X.Max);
                        if(p != x.end()) {
                            return p + 1;
                        }
                        return p;
                    }();

                    std::size_t const stride = [&]() -> std::size_t {
                        auto const s = std::distance(start, end) / (plotRegion.x * 2.0);
                        if(1 >= s) {
                            return 1;
                        }
                        return static_cast<std::size_t>(s);
                    }();

                    ImPlot::PlotLine(
                      plot_name,
                      &(*start),
                      y.data() + std::distance(x.begin(), start),
                      static_cast<std::size_t>(std::distance(start, end)) / stride,
                      0,
                      0,
                      sizeof(double) * stride);
                };

                for(auto const& plot : plots) {
                    addPlot(plot.name.c_str(), plot.x, plot.y);
                    ImPlot::NextColormapColor();
                }

                ImPlot::EndPlot();
            }
        };


void SetMainWindowStyle(){

    ImGuiStyle &style = ImGui::GetStyle();

    style.Colors[ImGuiCol_Text] = ImVec4(1/255.0f, 1/255.0f, 1/255.0f, 100/100.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(255/255.0f, 255/255.0f, 255/255.0f, 100/100.0f);
    style.Colors[ImGuiCol_Border] =  ImVec4(255/255.0f, 255/255.0f, 255/255.0f, 100/100.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(255/255.0f, 255/255.0f, 255/255.0f, 100/100.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(255/255.0f, 255/255.0f, 255/255.0f, 100/100.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(255/255.0f, 255/255.0f, 255/255.0f, 100/100.0f);

    // Die Farben bei Hovern und klicken der Achsen 
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(240/255.0f, 240/255.0f, 240/255.0f, 100/100.0f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(240/255.0f, 240/255.0f, 240/255.0f, 100/100.0f);
}



// Main Function to set the window 
void SetMainWindow(){
    
    SetMainWindowStyle(); 

    ImGui:: SetCursorPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.18f, ImGui::GetIO().DisplaySize.y * 0.05f)); 

    ImGui::BeginChild("MainWindow", ImVec2(ImGui::GetIO().DisplaySize.x * 0.82f, ImGui::GetIO().DisplaySize.y * 0.65f), true); 

    static constexpr std::size_t N    = 100000;
    static constexpr double      step = 0.001;

    std::vector<double> x1_data{};
    x1_data.resize(N);
    std::vector<double> y1_data{};
    y1_data.resize(N);

    std::vector<double> x2_data{};
    x2_data.resize(N);
    std::vector<double> y2_data{};
    y2_data.resize(N);

    std::vector<double> x3_data{};
    x3_data.resize(N);
    std::vector<double> y3_data{};
    y3_data.resize(N);

    for(std::size_t i{}; i < N; ++i) {
        x1_data[i] = i * step;
        y1_data[i] = std::sin(x1_data[i]);
        x2_data[i] = x1_data[i];
        y2_data[i] = std::sin(x2_data[i] + (std::numbers::pi * 2.0 / 3.0));
        x3_data[i] = x1_data[i];
        y3_data[i] = std::sin(x3_data[i] + 2.0 * (std::numbers::pi * 2.0 / 3.0));
    }

    struct PlotRef {
        std::string          name;
        std::vector<double>& x;
        std::vector<double>& y;
    };

    std::vector<PlotRef> plotData;
    plotData.emplace_back("P1", x1_data, y1_data);
    plotData.emplace_back("P2", x2_data, y2_data);
    plotData.emplace_back("P3", x3_data, y3_data);


    addPlots("Plots", plotData, [](auto x_min, auto x_max) {
            ImPlot::SetupAxes("x", "y", 0, ImPlotAxisFlags_RangeFit | ImPlotAxisFlags_AutoFit);
            ImPlot::SetupAxisLimitsConstraints(ImAxis_X1, x_min, x_max);
        });

     ImGui::Text("Dies ist ein Text im Child-Element.");

    ImGui::EndChild(); 
}
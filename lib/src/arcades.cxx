# include <arcades/arcades.hxx>
# include <config/version.hxx>
# include <utils/utils.hxx>

utils::Version arcades::get_version() {
    return {ARCADES_VERSION};
}
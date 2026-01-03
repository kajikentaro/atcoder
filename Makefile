build:
	cd infra && docker buildx build --platform linux/amd64,linux/arm64 -t kajindowsxp/atcoder:1.0.0 --push .
